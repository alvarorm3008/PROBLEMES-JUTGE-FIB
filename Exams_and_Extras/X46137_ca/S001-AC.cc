#include <vector>
#include <iostream>
using namespace std;

bool compensada (int na, int nb) {
    return abs(na-nb) <= 2;
}

void bt (int i, int na, int nb, string& sol, int n) {
    if (i == n) cout << sol << endl;
    else {
        if (compensada (na+1, nb)) {
            sol[i] = 'a';
            bt (i+1, na+1, nb, sol, n);
        }
        if (compensada (na, nb+1)) {
            sol[i] = 'b';
            bt (i+1, na, nb+1, sol, n);
        }
    }
}

int main () {
    int n;
    cin >> n;
    string sol (n, ' ');
    bt(0, 0, 0, sol, n);

}