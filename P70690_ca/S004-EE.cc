#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<vector<char>> Tablero;

typedef pair<int, int> pos;

const int x[4] = {-1, 0, 1, 0};
const int y[4] = {0, 1, 0, -1};
//vector <pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}

bool pos_valida (const Tablero& t, int x, int y) {
    int n = t.size();
    int m = t[0].size();
    return x >= 0 and x < n and y >= 0 and y < m;
}

bool dfs (Tablero& mapa, int f, int c) {
    if (mapa[f][c] != 'X') {
        if (mapa[f][c] == 't') return true;
        else {
            mapa[f][c] = 'X';
            for (int i = 0; i < 4; ++i) {
                int x_seg, y_seg;
                x_seg = f + y[i];
                y_seg = c + y[i];
                if (pos_valida (mapa, x_seg, y_seg))
                    if (dfs(mapa, x_seg, y_seg)) return true;
            }
        }
    }
}

int main () {
    int n, m;

    cin >> n >> m;
    Tablero tablero (n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> tablero[i][j];

    int f, c;
    cin >> f >> c;
    cout << (dfs(tablero, f-1, c-1) ? "yes" : "no") << endl;

}