#include "quickSortString.h"

int particion(std::string arr[], int ini, int fin) {
    std::string pivote = arr[ini];
    int i = ini;

    for (int j = ini + 1; j <= fin; j++) {
        if (arr[j] < pivote) {
            i++;
            std::string tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    arr[ini] = arr[i];
    arr[i] = pivote;
    return i;
}

void quickSortString(std::string arr[], int ini, int fin) {
    if (ini < fin) {
        int pi = particion(arr, ini, fin);
        quickSortString(arr, ini, pi - 1);
        quickSortString(arr, pi + 1, fin);
    }
}