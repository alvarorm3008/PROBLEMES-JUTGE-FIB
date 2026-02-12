#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef vector<bool> VB;

void escriu (int f, int c, const Tablero& t) {
    for (int i = 0; i < f; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << t[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void bt (int i, int f, int c, Tablero& t, VB&col) {
    if (i == f) escriu (f, c, t);
    else {
        for (int j = 0; j < c; ++j) {
            if (not col[j]) {
                col[j] = true;
                t[i][j] = 'R';
                bt (i+1, f, c, t, col);
                col[j] = false;
                t[i][j] = '.';
            }
        }
    }
}

int main () {
    int f, c;
    cin >> f >> c;
    Tablero t(f, vector<char> (c, '.'));
    VB col (c, false);
    bt (0, f, c, t, col);

}