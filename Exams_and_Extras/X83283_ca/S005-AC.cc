#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graf;

int bfs (Graf& g) {
    int n = g.size();
    queue<int> q; //vertex i distancia
    vector<int> dist (n, -1);
    int d_max = 0;
    int v_max = 0;
    q.push (0);
    dist[0] = 0;

    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                q.push(v);
                dist[v] = dist[u] + 1;
                if (dist[v] > d_max) {
                    d_max = dist[v];
                    v_max = v;
                }
                else if (dist[v] == d_max and v < v_max) v_max = v;
            }
        }
    }
    return v_max;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout << bfs (g) << endl;
    }
}