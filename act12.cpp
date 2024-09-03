// Act 1.2 - Algoritmos de Búsqueda y Ordenamiento
// Autor: Bruno Vázquez Espinoza - A00838521
// Fecha: 03/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Intercambia dos elementos
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Exchange Sort: O(n^2)
// Ordena el vector comparando y cambiando cada par de elementos.
void exchangeSort(vector<int> &arr) {
    int n = arr.size(); // Tamaño del vector
    for(int i = 0; i < n-1; i++) { // Itera sobre el vector hasta el penúltimo elemento
        for(int j = i+1; j < n; j++) { // Compara el elemento actual con todos los siguientes
            if(arr[i] > arr[j]) { // Si el elemento actual es mayor que el siguiente, intercambiarlos
                swap(arr[i], arr[j]); // Realiza el intercambio
            }
        }
    }
}

// Bubble Sort: O(n^2)
// Ordena el vector intercambiando elementos adyacentes si están en el orden incorrecto.
void bubbleSort(vector<int> &arr) {
    int n = arr.size(); // Tamaño del vector
    for(int i = 0; i < n-1; i++) { // Itera sobre el vector
        for(int j = 0; j < n-i-1; j++) { // Itera hasta el elemento no ordenado más grande
            if(arr[j] > arr[j+1]) { // Si el elemento actual es mayor que el siguiente, intercambiarlos
                swap(arr[j], arr[j+1]); // Realiza el intercambio
            }
        }
    }
}

// Selection Sort: O(n^2)
// Encuentra el elemento mínimo en el vector y lo coloca en su posición correcta.
void selectionSort(vector<int> &arr) {
    int n = arr.size(); // Tamaño del vector
    for(int i = 0; i < n-1; i++) { // Itera sobre el vector hasta el penúltimo elemento
        int minIdx = i; // Inicializa el índice del mínimo
        for(int j = i+1; j < n; j++) { // Encuentra el elemento más pequeño en la sublista no ordenada
            if(arr[j] < arr[minIdx]) { // Si encuentra un elemento más pequeño, actualiza el índice del mínimo
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]); // Coloca el elemento más pequeño en su posición correcta
    }
}

// Insertion Sort: O(n^2)
// Ordena el vector insertando cada elemento en su lugar en la parte ordenada del vector.
void insertionSort(vector<int> &arr) {
    int n = arr.size(); // Tamaño del vector
    for(int i = 1; i < n; i++) { // Itera sobre cada elemento, comenzando por el segundo
        int key = arr[i]; // Guarda el valor actual
        int j = i - 1; // Comienza desde el elemento anterior
        while(j >= 0 && arr[j] > key) { // Desplaza los elementos más grandes hacia la derecha
            arr[j + 1] = arr[j]; // Desplazamiento
            j--;
        }
        arr[j + 1] = key; // Inserta el elemento en su posición correcta
    }
}

// Merge Function for Merge Sort: O(n)
// Combina dos sublistas ordenadas en una única lista ordenada.
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamaño de la primera sublista
    int n2 = right - mid; // Tamaño de la segunda sublista
    
    vector<int> L(n1), R(n2); // Vectores temporales para guardar las sublistas
    
    for(int i = 0; i < n1; i++) { // Copia los datos a las sublistas temporales
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++) { // Copia los datos a las sublistas temporales
        R[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left; // Inicializa los índices
    
    // Combina las sublistas en la lista principal
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copia los elementos restantes de L, si los hay
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copia los elementos restantes de R, si los hay
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort: O(n log n)
// Divide el vector en sublistas, las ordena y las combina.
void mergeSort(vector<int> &arr, int left, int right) {
    if(left < right) { // Verifica si hay más de un elemento en la sublista
        int mid = left + (right - left) / 2; // Encuentra el punto medio
        mergeSort(arr, left, mid); // Ordena la primera mitad
        mergeSort(arr, mid + 1, right); // Ordena la segunda mitad
        merge(arr, left, mid, right); // Combina las dos mitades ordenadas
    }
}

// Partition Function for Quick Sort: O(n)
// Organiza el vector de manera que todos los elementos menores al pivote estén a su izquierda y los mayores a su derecha.
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Elige el último elemento como pivote
    int i = low - 1; // Índice del elemento más pequeño
    
    for(int j = low; j < high; j++) { // Recorre el vector
        if(arr[j] < pivot) { // Si el elemento actual es menor que el pivote
            i++;
            swap(arr[i], arr[j]); // Intercambia los elementos
        }
    }
    swap(arr[i + 1], arr[high]); // Coloca el pivote en su posición correcta
    return i + 1; // Devuelve el índice del pivote
}

// Quick Sort: O(n log n)
// Ordena el vector dividiéndolo en sublistas alrededor de un pivote.
void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) { // Verifica si hay más de un elemento en la sublista
        int pi = partition(arr, low, high); // Encuentra el índice de partición
        quickSort(arr, low, pi - 1); // Ordena la sublista izquierda
        quickSort(arr, pi + 1, high); // Ordena la sublista derecha
    }
}

// Búsqueda Secuencial: O(n)
// Recorre el vector de principio a fin para encontrar el elemento deseado.
int busqSecuencial(vector<int> &arr, int target) {
    for(int i = 0; i < arr.size(); i++) { // Itera sobre el vector
        if(arr[i] == target) { // Si encuentra el elemento, devuelve su índice
            return i;
        }
    }
    return -1; // Si no encuentra el elemento, devuelve -1
}

// Búsqueda Binaria: O(log n)
// Busca un elemento en un vector ordenado dividiendo el rango de búsqueda a la mitad en cada paso.
int busqBinaria(vector<int> &arr, int target, int left, int right) {
    while(left <= right) { // Mientras haya elementos en el rango de búsqueda
        int mid = left + (right - left) / 2; // Encuentra el punto medio
        if(arr[mid] == target) { // Si el elemento medio es el objetivo, devuelve su índice
            return mid;
        }
        if(arr[mid] < target) { // Si el objetivo es mayor que el elemento medio, ignora la mitad izquierda
            left = mid + 1;
        } else { // Si el objetivo es menor que el elemento medio, ignora la mitad derecha
            right = mid - 1;
        }
    }
    return -1; // Si no encuentra el elemento, devuelve -1
}

int main() {
    // Casos de prueba predefinidos
    vector<vector<int> > testCases; // Declara el vector de vectores

    // Agrega los casos de prueba individualmente
    int arr1[] = {34, 7, 23, 32, 5, 62}; // Primer caso de prueba
    int arr2[] = {10, 20, 30, 40, 50};  // Segundo caso de prueba
    int arr3[] = {5, 4, 3, 2, 1};       // Tercer caso de prueba
    int arr4[] = {100, 90, 80, 70, 60, 50, 40}; // Cuarto caso de prueba

    testCases.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    testCases.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    testCases.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));
    testCases.push_back(vector<int>(arr4, arr4 + sizeof(arr4) / sizeof(int)));
    
    // Itera sobre cada caso de prueba
    for(int i = 0; i < testCases.size(); i++) {
        cout << "\nCaso de prueba " << i + 1 << ":\n";
        vector<int> arr = testCases[i];
        
        quickSort(arr, 0, arr.size() - 1); // Aplica QuickSort
        
        cout << "Vector ordenado: ";
        for(int j = 0; j < arr.size(); j++) { // Muestra el vector ordenado
            cout << arr[j] << " ";
        }
        cout << endl;
        
        // Realiza una búsqueda secuencial y binaria
        int target = arr[2]; // Buscar el tercer elemento como ejemplo
        cout << "Buscando " << target << "...\n";
        int idxSec = busqSecuencial(arr, target); // Búsqueda secuencial
        int idxBin = busqBinaria(arr, target, 0, arr.size() - 1); // Búsqueda binaria
        
        cout << "Resultado de búsqueda secuencial: " << idxSec << endl;
        cout << "Resultado de búsqueda binaria: " << idxBin << endl;
    }
    
    // Pregunta si el usuario quiere ingresar sus propios datos
    char choice;
    cout << "\n¿Desea ingresar sus propios datos? (s/n): ";
    cin >> choice;
    
    if(choice == 's') {
        int n;
        cout << "Ingrese el número de elementos: ";
        cin >> n;
        
        vector<int> arr(n);
        cout << "Ingrese los elementos:\n";
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        quickSort(arr, 0, n - 1); // Aplica QuickSort
        
        cout << "Vector ordenado: ";
        for(int j = 0; j < arr.size(); j++) { // Muestra el vector ordenado
            cout << arr[j] << " ";
        }
        cout << endl;
        
        int busquedas;
        cout << "Ingrese el número de búsquedas que desea realizar: ";
        cin >> busquedas;
        
        for(int i = 0; i < busquedas; i++) {
            int target;
            cout << "Ingrese el elemento a buscar: ";
            cin >> target;
            
            int idxSec = busqSecuencial(arr, target); // Búsqueda secuencial
            int idxBin = busqBinaria(arr, target, 0, n - 1); // Búsqueda binaria
            
            cout << "Resultado de búsqueda secuencial: " << idxSec << endl;
            cout << "Resultado de búsqueda binaria: " << idxBin << endl;
        }
    }
    
    return 0;
}