#include <iostream>
#include <vector>
using namespace std;

bool es_vocal (char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

void bt (int i, int n, int max, string& sol, int cont_x, int cont_y, int cont_z) {
    if (cont_x >= max or cont_y >= max or cont_z >= max) return;
    if (i == n) cout << sol << endl;
    else {
        sol[i] = 'x';
        bt (i+1, n, max, sol, cont_x+1, 0, 0);
        sol[i] = 'y';
        bt (i+1, n, max, sol, 0, cont_y+1, 0);
        sol[i] = 'z';
        bt (i+1, n, max, sol, 0, 0, cont_z+1);
    }
}


int main () {
    int n, c;
    while (cin >> n >> c) {

        string sol (n, ' ');
        bt (0, n, c+1, sol, 0, 0, 0);

        cout << string (20, '-') << endl;
    }
   

}