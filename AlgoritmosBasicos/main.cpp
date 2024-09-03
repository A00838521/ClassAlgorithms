#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
    int n = 10;
    int M = 1000;
    double m, m1 = 0.0;
    srand(100);
    if(argc > 1) {
        n = atoi(argv[1]);
    }
    for(int i = 0; i < 10; i++) {
        double a = rand() % M;
        m += a / n;
        m1 += a * a /n;
    }
    
    cout << "Promedio: " << m << endl;
    cout << "Desviacion: " << sqrt(m1 - m * m) << endl;

    return 0;
}