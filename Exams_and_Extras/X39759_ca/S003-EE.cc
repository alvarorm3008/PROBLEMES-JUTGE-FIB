#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Matriu;

const int x[8] = {-1, -2, -2, -1, 2, 2, 2, 1};
const int y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

typedef pair<int, int> pos;

bool valida (int n, int m, int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < m;
}


bool bfs (const pos& obj, pos& ini, int n, int m, int& objectius, int& salts) {
    Matriu dist (n, vector<int> (m, -1));
    queue<pos> q;
    if (ini == obj) {
        ++objectius;
        return true;
    }
    q.push(ini);
    dist[ini.first][ini.second] = 0;

    while (not q.empty()) {
        pos act = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int x_seg = act.first + x[i];
            int y_seg = act.second + y[i];
            if (valida(n, m, x_seg, y_seg) and dist[x_seg][y_seg] == -1) {
                dist[x_seg][y_seg] = dist[act.first][act.second] + 1;
                if (pos(x_seg, y_seg) == obj) {
                    ++objectius;
                    salts += dist[x_seg][y_seg];
                    return true;
                }
                q.push({x_seg, y_seg});
            }
        }
    }
    return false;
}

int main () {
    int n, m, W, L, k;
    while (cin >> n >> m >> W >> L >> k) {
        vector<pos> posicions (k);
        posicions[0] = {0, 0};
        for (int i = 1; i <= k; ++i) {
            cin >> posicions[i].first >> posicions[i].second;
        }
        int objectius = 0;
        int salts = 0;
        bool arribem = true;
        for (int i = 1; i <= k and arribem; ++i) {
            arribem = bfs(posicions[i], posicions[i-1], n, m, objectius, salts);
        }
        int total = W*objectius - L*salts;
        cout << total << endl;
    }
}