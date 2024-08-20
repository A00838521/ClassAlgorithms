#include <iostream>
#include "quickSort.h"

using namespace std;

int main() {
    int arreglo[8] = {5, 3, 8, 6, 2, 7, 1, 4};
    
    cout << "Arreglo original: ";
    for (int i = 0; i < 8; i++) {
        cout << arreglo[i] << " ";
    }

    quickSort(arreglo, 0, 7);

    cout << endl << "Arreglo ordenado: ";
    for (int i = 0; i < 8; i++) {
        cout << arreglo[i] << " ";
    }

    return 0;
}