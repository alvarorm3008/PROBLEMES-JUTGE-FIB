#include <iostream>
#include <vector>
using namespace std;


bool equilibrada (int x, int y, int d) {
    return abs (x-y) <= d;
}

void escriu (int n, const vector<int>& sol) {
    cout << '(';
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ',';
        cout << sol[i]; 
    }
    cout << ')' << endl;
}

void bt (int i, int n, int d, vector<int>& sol, vector<bool>& usat) {
    if (i == n) escriu(n, sol);
    else {
        for (int j = 0; j < n; ++j) {
                    if ((i == 0 or (equilibrada (sol[i-1], j+1, d) and not usat[j+1]))) {
                    sol[i] = j+1;
                    usat[j+1] = true;
                    bt (i+1, n, d, sol, usat);
                    usat[j+1] = false;
            }
        }
    }
}

int main () {
    int n, d;
    cin >> n >> d;
    vector<int> sol (n);
    vector<bool> usat(n, false);
    bt (0, n, d, sol, usat);
}