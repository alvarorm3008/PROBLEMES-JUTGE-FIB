#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tablero;

void escriu (const Tablero& sol, int f, int c) {
    for (int i = 0; i < f; ++i)
        for (int j =0 ; j < c; ++j) cout << sol[i][j];
    cout << endl;
}

void torres (int i, Tablero& sol, vector<bool>& col, int f, int c) {
    if (i == f) escriu (sol, f, c);
    else {
        for (int j = 0; j < c; ++j) {
            if (not col[j]) {
                col[j] = true;
                sol[i][j] = 'R';
                torres (i+1, sol, col, f, c);
                col[j] = false;
                sol[i][j] = '.';
            }
        }
    }
}
 
int main () {
    int f, c;
    cin >> f >> c;
    vector<bool> col (c, false);
    Tablero sol (f, vector<char> (c, '.'));
    torres (0, sol, col, f, c);
}

/*
#include <iostream>
#include <vector>
using namespace std;

çç

void escriu (const vector<int>& sol, int f, int c) {
    for (int i = 0; i < f, ++i)
        for (int j =0 ; j < c; ++j) {
            if (sol[i] == j) cout << 'R;
            else cout << '.';
        }
    cout << endl;
}

void torres (int i, vector<int>& sol, vector<bool>& col, int f, int c) {
    if (i == f) escriu (sol, f, c);
    else {
        for (int j = 0; j < c; ++j) {
            if (not col[j]) {
                col[j] = true;
                sol[i] = j;
                torres (i+1, sol, col, f, c);
                col[j] = false;
            }
        }
    }
}
 
int main () {
    int f, c;
    cin >> f >> c;
    vector<bool> col (c, false);
    vector<int> sol (f);
    torres (0, sol, col, f, c);
}
*/