#include <iostream>
using namespace std;

void info_secuencia(int& suma, int& ultimo) {
    int n;
    cin >> n;
    ultimo = suma = 0;
    while (n != 0) {
        suma += n;
        ultimo = n;
        cin >> n;
    }
}

int main() {
    int suma_ini, ultimo_ini;
    suma_ini = 0;
    info_secuencia(suma_ini, ultimo_ini);

    int suma, ultimo = 1;
    int cont = 1;

    while(ultimo != 0) {
        info_secuencia(suma, ultimo);
        if (suma == suma_ini and ultimo == ultimo_ini) {
            ++cont;
        }
    }
    cout << cont << endl;
}
