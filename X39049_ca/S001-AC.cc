#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

VI mult (const VI& v1, const VI& v2, int n) {
    VI sol(n);
    for (int i = 0; i < n; ++i) {
        sol[i] = v1[v2[i]];
    }
    return sol;
}

void pot_permu (const VI& v, int k, VI& sol, int n) {
    if (k == 0) {
        for (int i = 0; i < n; ++i) sol[i] = i;
    }
    else {
        VI aux (n);
        pot_permu (v, k/2, aux, n);
        //HI: aux = v^k/2
        sol = mult (aux, aux, n);
        //A: sol = v^k/2*v^k/2
        if (k % 2 == 1) sol = mult (sol, v, n);
    }
}

int main () {
    int n;
    while (cin >> n) {
        VI v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int k;
        cin >> k;
        vector <int> sol (n);
        pot_permu (v, k, sol, n);

        for (int i = 0; i < n; ++i) {
            if (i != 0) cout << ' ';
            cout << sol[i];
        }
        cout << endl;
    }
}