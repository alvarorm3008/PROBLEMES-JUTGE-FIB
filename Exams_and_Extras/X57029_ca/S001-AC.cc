#include <iostream>
#include <vector>
using namespace std;

void bt (int i, int n, string& sol, int altura) {
    if (i == n) cout << sol << endl;
    else {
        if (altura > 0) {
            sol[i] = 'd';
            bt (i+1, n, sol, altura-1);
        }
        sol[i] = 'h';
        bt (i+1, n, sol, altura);
        sol[i] = 'u';
        bt (i+1, n, sol, altura+1);
    }
}

int main () {
    int n;
    cin >> n;
    string sol;
    sol = string (n, ' ');
    bt (0, n, sol, 0);
}