#include <iostream>

using namespace std;

bool esPrimo(int);

int main(int argc, char *argv[]) {
    int n;
    for(int i=0; i< argc;i++){
        cout << "Argumento " << i << ": " << argv[i] << endl;
    }
    if(argc > 1){
        n = atoi(argv[1]);
        if (esPrimo(n)){
            cout << "El numero " << n << " es primo" << endl;
        } else {
            cout << "El numero " << n << " no es primo" << endl;
        }
    } else {
        cout << "No se ingreso un numero" << endl;
        return 1;
    }
}

bool esPrimo(int n) {
    for(int i = 2; i < n; i++){
        if(n % i == 0){ // n es divisible por i
            return false; // n no es primo
        }
        return true; // n es primo
    }
}