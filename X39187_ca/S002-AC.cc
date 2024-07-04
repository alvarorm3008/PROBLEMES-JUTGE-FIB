#include <iostream>
#include <string>
using namespace std;

/*
void acciones (int i, string& sol, int mon, int acc, int n) {
    if (i == n) cout << sol << endl;
    else {
        //comprar
        if (mon > 0) {
            sol[i] = 'b';
            acciones(i+1, sol, mon-1, acc+1, n);
        }
        if (acc > 0) {
            sol[i] = 's';
            acciones(i+1, sol, mon+1, acc-1, n);
        }
    }
}*/

void acciones (int i, string& sol, int mon, int acc, int n) {
    if (mon < 0 or acc < 0) return; 
    if (i == n) cout << sol << endl;
    else {
        //comprar
            sol[i] = 'b';
            acciones(i+1, sol, mon-1, acc+1, n);
        //vender
            sol[i] = 's';
            acciones(i+1, sol, mon+1, acc-1, n);
    }
}

int main () {
    int n, c; 
    cin >> n >> c;

    string sol(n, ' ');
    acciones (0, sol, c, 0, n);
}