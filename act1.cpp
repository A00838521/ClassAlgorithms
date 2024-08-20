// Act 1.1 - Funciones Iterativas, Recursivas y su análisis de Complejidad
// Autor: Bruno Vázquez Espinoza - A00838521
// Fecha: 16/08/2024

#include <iostream>

using namespace std;

// Complejidad O(n)
int sumaIterativa(int n) { 
    int suma = 0;
    for (int i = 1; i <= n; i++) { // Itera desde 1 hasta n
        suma += i; // Agrega el número actual a la suma
    }
    return suma;
}

// Complejidad O(n)
int sumaRecursiva(int n) {
    if (n == 0) { // Caso base: si n es 0, devuelve 0
        return 0;
    } else { // Caso recursivo: suma n al resultado de la suma de los números anteriores
        return n + sumaRecursiva(n - 1);
    }
}

// Complejidad O(1)
int sumaDirecta(int n) { 
    return n * (n + 1) / 2; // Utiliza la fórmula para la suma de una serie aritmética
}

// Ejercicio 2

// Complejidad O(n)
int OTresNMasUnoRecursiva(int n) { 
    if (n == 1) { // Caso base: si n es 1, devuelve 1
        return 1;
    } else if (n % 2 == 0) { // Caso recursivo: si n es par, divide n entre 2
        return OTresNMasUnoRecursiva(n / 2);
    } else { // Caso recursivo: si n es impar, multiplica n por 3 y suma 1
        return OTresNMasUnoRecursiva(3 * n + 1);
    }
}

// Complejidad O(n)
int OTresNMasUnoIterativa(int n) { 
    while (n != 1) { // Mientras n no sea 1
        if (n % 2 == 0) { // Si n es par, divide n entre 2
            n /= 2;
        } else { // Si n es impar, multiplica n por 3 y suma 1
            n = 3 * n + 1;
        }
    }
    return n; // Devuelve 1
}

int main() {
    int n;
    cin >> n;

    cout << sumaIterativa(n) << " Complejidad: O(n)" << endl; // Imprime la suma calculada de forma iterativa
    cout << sumaRecursiva(n) << " Complejidad: O(n)" << endl; // Imprime la suma calculada de forma recursiva
    cout << sumaDirecta(n) << " Complejidad: O(1)" << endl; // Imprime la suma calculada directamente

    // Cálculo del total de pasos para el problema 3n+1
    cout << "Pasos necesarios para llegar a 1 usando 3n+1 (recursiva) para " << n << ": " << OTresNMasUnoRecursiva(n) << endl;
    cout << "Pasos necesarios para llegar a 1 usando 3n+1 (iterativa) para " << n << ": " << OTresNMasUnoIterativa(n) << endl;

    // Cálculo del total de pasos para los primeros 100 enteros
    for (int i = 1; i <= 100; i++) {
        cout << "Numero: " << i << " - Pasos: " << OTresNMasUnoIterativa(i) << endl;
    }

    return 0;
}