#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int, int> pos;

const int X[8] = {-1, 0, 1, 0, -1, -1, 1, 1}; //las cuatro ultimas son las de los fantasmas
const int Y[8] = {0, 1, 0, -1, -1, 1, 1, -1};

bool ok (int f, int c, int x, int y) {
    return x >= 0 and y >= 0 and x < f and y < c;
}

bool bfs (Tablero& t, pos& ini, int f, int c) {
    if (t[ini.first][ini.second] == 'B') return true;
    t[ini.first][ini.second] = 'X';

    for (int i = 0; i < 4; ++i) {
        pos next = {ini.first + X[i], ini.second + Y[i]};
        if (ok (f, c, next.first, next.first) and t[next.first][next.second] != 'X') {
            if (bfs (t, next, f, c)) return true;
        }
    }
    return false;
}

int main () {
    int f, c;
    while (cin >> f >> c) {
        Tablero t (f, vector<char> (c));
        vector<pos> fantasmes;
        pos ini;
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin  >> t[i][j];
                if (t[i][j] == 'P') ini = {i, j};
                else if (t[i][j] == 'F') fantasmes.push_back({i, j});
            }
        }
        for (int i = 0; i < fantasmes.size(); ++i) {
            pos fa = fantasmes[i];
            t[fa.first][fa.second] = 'X';
            for (int j = 0; j < 8; ++j) {
                int x = fa.first + X[j];
                int y = fa.second + Y[j];
                if (ok (f, c, x, y)) t[x][y] = 'X';
            }
        }
        if (t[ini.first][ini.second] == 'X') cout << "no" << endl;
        else cout << ((bfs(t, ini, f, c)) ? "si" : "no")  << endl;
    }
}