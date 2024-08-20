#include <iostream>
#include "quickSort.h"
#include "quickSortString.h"
#include <string>

using namespace std;

int main() {

    // Arreglo de enteros
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

    // Arreglo de strings

    string arregloString[8] = {"hola", "adios", "buenos", "dias", "noches", "tardes", "mañanas", "mediodia"};

    cout << endl << "Arreglo original: ";
    for (int i = 0; i < 8; i++) {
        cout << arregloString[i] << " ";
    }

    quickSortString(arregloString, 0, 7);

    cout << endl << "Arreglo ordenado: ";
    for (int i = 0; i < 8; i++) {
        cout << arregloString[i] << " ";
    }

    return 0;
}