#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef vector<vector<bool>> Matriu;
typedef pair<int, int> pos;

const int x[4] = {-1, 0, 1, 0};
const int y[4] = {0, 1, 0, -1};

bool valida (int n, int m, int x, int y, const Tablero& t) {
    return x >= 0 and y >= 0 and x < n and y < m and t[x][y] != 'X';
}

int bfs (Tablero& t, int f, int c) {
    int n = t.size();
    int m = t[0].size();
    int cont = 0;
    Matriu usat (n, vector<bool> (m, false));
    usat[f][c] = true;
    queue<pos> q;
    q.push ({f, c});
    
    while (not q.empty()) {
        pos act = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x_seg = x[i] + act.first;
            int y_seg = y[i] + act.second;
            if (valida (n, m, x_seg, y_seg, t) and not usat[x_seg][y_seg]) {
                if (t[x_seg][y_seg] == 't') ++cont;
                q.push ({x_seg, y_seg});
                usat[x_seg][y_seg] = true;
            }
        }
    }
    return cont;
}

int main () {
    int n, m;
    cin >> n >> m;
    Tablero t (n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> t[i][j];
    }

    int f, c;
    cin >> f >> c;
    cout << bfs (t, f-1, c-1) << endl;
}