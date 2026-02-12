#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

const int infinit = INT_MAX;

const int x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

typedef vector<vector<char>> Tablero;
typedef pair<int, int> pos;

bool valida (int n, int m, int x, int y, const Tablero& t) {
    return x >= 0 and y >= 0 and x < n and y < m and t[x][y] != 'X';
}

int bfs (Tablero t, int f, int c, int n, int m) {
    queue<pos> q;
    q.push ({f, c});
    vector<vector<int>> dist (n, vector<int> (m, infinit));
    dist[f][c] = 0;

    while (not q.empty()) {
        pos act = q.front();
        q.pop();
        if (t[act.first][act.second] == 'p') return dist[act.first][act.second];
        for (int i = 0; i < 8; ++i) {
            int x_seg = act.first + x[i];
            int y_seg = act.second + y[i];
            if (valida (n, m, x_seg, y_seg, t) and dist[x_seg][y_seg] == infinit) {
                q.push ({x_seg, y_seg});
                dist[x_seg][y_seg] = dist[act.first][act.second] + 1;
            }
        }
    }
    return infinit;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Tablero t (n, vector<char> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cin >> t[i][j]; //mirar luego a ver si cuento el numero de pastanagas
        }
        int f, c;
        cin >> f >> c;
        int sol = bfs (t, f-1, c-1, n, m);
        if (sol == infinit) cout << "no" << endl;
        else cout << sol << endl;
    }
}