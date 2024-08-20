#include "quickSort.h"

// Complejidad O(n log n)
void quickSort(int arr[], int ini, int fin) {
    if(ini < fin) {
        int pivote = particion(arr,ini,fin);
        quickSort(arr,ini,pivote-1);
    }
}