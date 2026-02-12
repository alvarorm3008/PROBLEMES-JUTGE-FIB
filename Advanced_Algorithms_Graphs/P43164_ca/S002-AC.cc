#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef vector<vector<int>> Matriu;

int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};

bool valida (int n, int m, int x, int y, const Tablero& t) {
    return x >= 0 and y >= 0 and x < n and y < m and t[x][y] != 'X';
}

void bfs (Tablero& t, int f, int c, vector<int>& sol) {
    int n = t.size();
    int m = t[0].size();
    Matriu dist (n, vector<int> (m, -1));
    queue<pair<int, int>> q;
    q.push ({f, c});
    dist[f][c] = 0;

    while (not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int x_seg = X[i] + x;
            int y_seg = Y[i] + y;
            if (valida (n, m, x_seg, y_seg, t)) {
                if (dist[x_seg][y_seg] == -1) {
                    dist[x_seg][y_seg] = dist[x][y] + 1;
                    if (t[x_seg][y_seg] == 't') {
                        sol.push_back (dist[x_seg][y_seg]);
                    }
                    q.push({x_seg, y_seg});
                }
            }
        }
    }
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
    vector<int> sol;
    bfs (t, f-1, c-1, sol);
    if (sol.size() < 2) cout << "no es pot arribar a dos o mes tresors" << endl;
    else cout << "segona distancia maxima: " << sol[sol.size()-2] << endl;
}