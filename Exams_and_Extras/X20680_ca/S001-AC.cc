#include <iostream>
#include <vector>
using namespace std;

void bt (string& sol, int n, int max, int i, int cons_x, int cons_y, int cons_z) {
    if (cons_x == max or cons_y == max or cons_z == max) return;
    if (i == n) cout << sol << endl;
    else {
            sol[i] = 'x';
            bt (sol, n, max, i+1, cons_x+1, 0, 0);
            sol[i] = 'y';
            bt (sol, n, max, i+1, 0, cons_y+1, 0);
            sol[i] = 'z';
            bt (sol, n, max, i+1, 0, 0, cons_z+1);
        
     }
}

int main () {
    int n, c;
    while (cin >> n >> c) {
        string sol (n, ' ');
        bt (sol, n, c+1, 0, 0, 0, 0);
        cout << string (20, '-') << endl;
    }
}