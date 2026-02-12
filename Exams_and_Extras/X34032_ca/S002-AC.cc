#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef vector<vector<int>> Matriu;
typedef pair<int, int> pos;

const int infinit = INT_MAX;

const int XC[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int YC[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool valida (int n, int m, int x, int y, const Tablero& t) {
    return x >= 0 and y >= 0 and x < n and y < m and t[x][y] != 'X';
}

int bfs (Tablero& t, int f, int c) {
    int n = t.size();
    int m = t[0].size();
    queue<pos> q;
    q.push({f, c});
    Matriu dist (n, vector<int> (m, infinit));
    dist[f][c] = 0;
    t[f][c] = 'X';

    while (not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (t[x][y] == 'p') return dist[x][y];
        for (int i = 0; i < 8; ++i) {
            int x_seg = XC[i] + x;
            int y_seg = YC[i] + y;
            if (valida (n, m, x_seg, y_seg, t)) {
                dist[x_seg][y_seg] = dist[x][y] + 1;
                q.push({x_seg, y_seg});
                if (t[x_seg][y_seg] != 'p') t[x_seg][y_seg] = 'X';
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
            for (int j = 0; j < m; ++j) cin >> t[i][j];
        }

        int f, c;
        cin >> f >> c;
        int res = bfs (t, f-1, c-1);
        if (res == infinit) cout << "no" << endl;
        else cout << res << endl;
    }
}