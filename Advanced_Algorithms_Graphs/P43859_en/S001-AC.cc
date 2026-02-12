#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair <int, int> arc; //first siempre distancia o coste y second el vertice
typedef vector<vector<arc>> graf;

const int infinit = INT_MAX; //10e9

int dijkstra (const graf& g, int ini, int fin) {
    int n = g.size();
    vector <bool> vis (n, false);
    vector <int> dist (n, infinit);
    dist[ini] = 0;
    priority_queue <arc, vector<arc>, greater<arc>> pq;
    pq.push({0, ini});

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (not vis[u]) {
            vis[u] = true;
            if (u == fin) return dist[u];
            for (arc uv: g[u]) {
                int v = uv.second;
                int c = uv.first;
                if (dist[v] > dist[u] + c) {
                    dist[v] = dist[u] + c;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    return -1;
}

int main () {
    int n, m;
    while(cin >> n >> m) {
        graf g(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            g[u].push_back ({c, v});
        }
        int x, y;
        cin >> x >> y;
        
        int dist = dijkstra(g, x, y);
        if (dist == -1) cout << "no path from " << x << " to " << y << endl;
        else cout << dist << endl;
    }
}
