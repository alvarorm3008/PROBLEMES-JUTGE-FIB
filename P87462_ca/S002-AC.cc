#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int, int> pos;

const int X[8] = {-1, 0, 1, 0, -1, -1, 1, 1}; //las cuatro ultimas son las de los fantasmas
const int Y[8] = {0, 1, 0, -1, -1, 1, 1, -1};

bool bfs (Tablero& t, pos& ini) {
    queue <pos> q;
    if (t[ini.first][ini.second] == 'X') return false;
    t[ini.first][ini.second] = 'X';
    q.push(ini);

    while (not q.empty()) {
        pos act = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            pos next = {act.first + X[i], act.second + Y[i]};
            if (t[next.first][next.second] == 'B') return true;
            if (t[next.first][next.second] != 'X') {
                t[next.first][next.second] = 'X';
                q.push(next);
            }
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
            for (int j = 0; j < 8; ++j) {
                int x = fa.first + X[j];
                int y = fa.second + Y[j];
                t[x][y] = 'X';
            }
        }
        cout << ((bfs(t, ini)) ? "si" : "no")  << endl;
    }
}