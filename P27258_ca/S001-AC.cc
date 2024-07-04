#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;

typedef pair<int, int> pos;

const int X[4] = {-1, 0, 1, 0};
const int Y[4] = {0, 1, 0, -1};

bool pos_valida (int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

//act no visitada al entrar
bool dfs (Tablero& t, pos act, int n, int m) {
    if (t[act.first][act.second] == 'F') return true;
    t[act.first][act.second] = 'X';

    for (int i = 0; i < 4; ++i) {
        int x = act.first + X[i];
        int y = act.second + Y[i];
        if (pos_valida (x, y, n, m) and t[x][y] != 'X') {
            if (dfs(t, pos(x, y), n, m)) return true;
        }
    }
    return false;
}

int main () {
    int f, c;
    while (cin >> f >> c) {
        Tablero t (f, vector<char> (c));
        pos ini;
        vector<pos> mon;

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> t[i][j];
                if (t[i][j] == 'I') {
                    ini = {i, j};
                }
                else if (t[i][j] == 'M') {
                    mon.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < int(mon.size()); ++i){
            pos p = mon[i];
            for (int j = 0; j < 4; ++j) {
                int x = p.first + X[j];
                int y = p.second + Y[j];
                if (pos_valida(x, y, f, c)) t[x][y] = 'X';
            }
        }

        cout << (dfs(t, ini, f, c) ? "SI" : "NO")   << endl;
    }
}