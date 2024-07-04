#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int, int> pos;

const int X[4] = {-1, 0, 1, 0};
const int Y[4] = {0, 1, 0, -1};

bool ok (int n, int m, int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

bool bfs (int n, int m, Tablero& t, pos act) {
    if (t[act.first][act.second] == 'F') return true;
    t[act.first][act.second] = 'X';

    for (int i = 0; i < 4; ++i) {
        int x = X[i] + act.first;
        int y = Y[i] + act.second;
        if (ok (n, m, x, y) and t[x][y] != 'X') {
            if (bfs(n, m, t, pos ({x, y}))) return true;
        }
    }
    return false;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Tablero t (n, vector<char> (m));
        vector <pair<int, int>> monstres;
        pos ini;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> t[i][j];
                if (t[i][j] == 'I') {
                    ini = {i, j};
                }
                else if (t[i][j] == 'M') monstres.push_back ({i, j});
            }
        }
        for (int i = 0; i < monstres.size(); ++i) {
            pos p = monstres[i];
            for (int j = 0; j < 4; ++j) {
                int x = p.first + X[j];
                int y = p.second + Y[j];
                if (ok (n, m, x, y)) t[x][y] = 'X'; 
            }
        }
        cout << (bfs (n, m, t, ini) ? "SI" : "NO") << endl;
    }
}