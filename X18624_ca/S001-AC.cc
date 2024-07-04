#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool es_vocal (char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

void bt (int i, int n, int m, string & sol, const string& lletres) {
    if (i == n) cout << sol << endl;
    else {
        for (int j = 0; j < m; ++j) {
            char c = lletres[j];
            if (not es_vocal(c) or i == 0 or not es_vocal(sol[i-1])) {
                sol[i] = c;
                bt (i+1, n, m, sol, lletres);
            }
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        string sol (n, ' ');
        string lletres (m, ' ');
        for (int i = 0; i < m; ++i) {
            cin >> lletres[i];
        }
        sort (lletres.begin(), lletres.end());
        bt (0, n, m, sol, lletres);
        cout << string (10, '-') << endl;
    }
}