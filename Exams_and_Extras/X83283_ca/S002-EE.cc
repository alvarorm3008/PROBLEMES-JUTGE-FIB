#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int UNDEF = -1;

using namespace std;

typedef vector<vector<int>> graf;

int bfs (graf& g, int n, int m) {
    vector<int> dist (n, UNDEF);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (not q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : g[v]) {
            if (dist[w] == UNDEF) {
                dist[w] = dist[v] + 1;
                q.push(w);
            }
        }
    }
    int res = 0;
    for (int v = 1; v <= n; ++v) {
        if (dist[v] != UNDEF and dist[v] > dist[res]) res = v;
    }
    return res;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        graf g (n, vector<int> (n));
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if (m == 0) cout << 0 << endl;
        else cout << bfs (g, n, m) << endl;
    }
}