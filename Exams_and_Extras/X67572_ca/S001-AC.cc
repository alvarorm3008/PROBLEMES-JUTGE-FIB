#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> VS;
typedef vector<int> VI;

void escriu (int n, const VS& sol, const VS& paraules) {
    for (int i = 0; i < n; ++i) cout << sol[i];
    cout << endl;
}

void bt (int i, int n, VS& sol, const VS& paraules, vector<bool>& usat) {
    if (i == n) escriu (n, sol, paraules); 
    else {
        for (int j = 0; j < n; ++j) {
            string act = paraules[j];
            if (not usat[j] and (i == 0 or sol[i-1].back() != act[0])) {
                usat[j] = true;
                sol[i] = paraules[j];
                bt (i+1, n, sol, paraules, usat);
                usat[j] = false;
            }

        }
    }
}

int main () {
    int n;
    cin >> n;
    VS sol (n);
    VS paraules (n);
    vector<bool> usat (n, false);
    for (int i = 0; i < n; ++i) cin >> paraules[i];

    bt (0, n, sol, paraules, usat);
}