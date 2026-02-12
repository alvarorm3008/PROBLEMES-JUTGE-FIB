#include <iostream>
#include <vector>
using namespace std;

vector<bool> col, diag1, diag2;
int n;

int reinas (int i) {
    if (i == n) return 1;
    else {
        int cont = 0;
        for (int j = 0; j < n; ++j) {
            int d1 = i+j;
            int d2 = n-j-1+i;
            if (not col[j] and not diag1[d1] and not diag2[d2]) {
                col [j] = diag1 [d1] = diag2 [d2] = true;
                cont += reinas (i+1);
                col [j] = diag1 [d1] = diag2 [d2] = false;
            }
        }
        return cont;
    }
}

int main () {
    cin >> n;
    col = vector<bool> (n, false);
    diag1 = vector<bool> (2*n-1, false);
    diag2 = vector<bool> (2*n-1, false);

    cout << reinas (0) << endl;
}