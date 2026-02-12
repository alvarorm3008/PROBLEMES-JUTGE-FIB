#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef vector<vector<int>> Matriu;
typedef pair<int, int> pos;

const int XC[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int YC[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool pos_valida (int n, int m, int x, int y, Tablero& t) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

void bfs (Tablero& t, int f, int c, int& flors, int& d) {
    int n = t.size();
    int m = t[0].size();
    queue<pos> q;
    Matriu dist (n, vector<int> (m, -1));
    dist[f][c] = 0;
    q.push ({f, c});

    while (not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int x_seg = x + XC[i];
            int y_seg = y + YC[i];
            if (pos_valida(n, m, x_seg, y_seg, t) and t[x_seg][y_seg] != 'a' and dist[x_seg][y_seg] == -1) {
                dist[x_seg][y_seg] = dist[x][y]+1;
                
                if (t[x_seg][y_seg] == 'F') {
                    ++flors;
                    d += dist[x][y]+1;
                }
                q.push ({x_seg, y_seg});
            }
        }

    }
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n, m;
    cin >> n >> m;

    Tablero t (n, vector<char> (m));

    int f_ini, c_ini;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t[i][j];
            if (t[i][j] == 'C') {
                f_ini = i;
                c_ini = j;
            }
        }
    }

    int flors = 0;
    int dist = 0;

    bfs (t, f_ini, c_ini, flors, dist);

    if (flors != 0) {
        cout << "flors accessibles: " << flors<< endl;
        cout << "distancia mitjana: " << double(dist)/double(flors) << endl;
    }
    else cout << "el cavall no pot arribar a cap flor" << endl;

}