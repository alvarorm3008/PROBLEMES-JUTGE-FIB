#include <iostream>
#include <vector>
using namespace std;

void escriu (const vector<int>&sol) {
    for (int i = 0; i < sol.size(); ++i) cout << sol[i];
    cout << endl;
}


void bt (int i, int n, vector<int> sol, bool trobat) {
    if (i==3*n) escriu(sol);
    else {
        for (int j = 1; j <= 3*n / 2; ++j) {
                if (sol[i-1] != j and not trobat)
                    if (sol[i-1] == j) trobat = true;
                    sol[i] = j;
                    bt (i+1, n, sol, trobat);
        }
    }
}

int main () {
    int n;
    while (cin >> n) {
        vector<int> sol (3*n);
        bt (0, n, sol, false);
        cout << string (10, '*') << endl;
    }
}