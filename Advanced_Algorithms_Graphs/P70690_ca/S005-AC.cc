#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<vector<char>> Tablero;

typedef vector<pair< int, int>> pos;

const int x[4] = {-1, 0, 1, 0};
const int y[4] = {0, 1, 0, -1};

bool pos_valida (int x, int y, const Tablero& t) {
    int n_max = t.size();
    int m_max = t[0].size();
    return x >= 0 and x < n_max and y >= 0 and y < m_max;
}

bool dfs (int f, int c, Tablero& t) {
    if (t[f][c] != 'X') {
        if (t[f][c] == 't') return true;
        else {
            t[f][c] = 'X';
            for (int i = 0; i < 4; ++i) {
                int x_seg, y_seg;
                x_seg = f + x[i];
                y_seg = c + y[i];
                if (pos_valida(x_seg, y_seg, t)) {
                    if (dfs (x_seg, y_seg, t)) return true;
                }
            }

        }
    }
    return false;
}

int main () {
    int n, m;
    cin >> n >> m;
    Tablero t (n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t[i][j];
        }
    }

    int f, c;
    cin >> f >> c;
    if (dfs(f-1, c-1, t)) cout << "yes" << endl;
    else cout << "no" << endl;
}