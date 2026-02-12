#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;

const int X[4] = {-1, 0, 1, 0};
const int Y[4] = {0, 1, 0, -1};

bool valida (int n, int m, int x, int y, const Tablero& t) {
    return x >= 0 and y >= 0 and x < n and y < m and t[x][y] != 'X';
}

int bfs (Tablero& t, int f, int c) {
    int n = t.size();
    int m = t[0].size();
    queue<pair<pair<int, int>, int>> q;
    q.push ({{f, c}, 0});
    t[f][c] = 'X';

    while (not q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x_seg = x + X[i];
            int y_seg = y + Y[i];
            if (valida (n, m, x_seg, y_seg, t)) {
                if (t[x_seg][y_seg] == 't') return dist+1;
                t[x_seg][y_seg] = 'X';
                q.push({{x_seg, y_seg}, dist + 1});
            }
        }
    }
    return -1;
}


int main () {
    int n, m;
    cin >> n >> m;
    Tablero t (n, vector<char> (m));
    for (int i = 0; i < n; ++i ){
        for (int j = 0; j < m; ++j) {
            cin >> t[i][j];
        }
    }
    int f, c;
    cin >> f >> c;
    int res = bfs (t, f-1, c-1);
    if (res == -1) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia minima: " << res << endl;
}