#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> arc; //primero coste second vertex ady
typedef vector<vector<arc>> Graf;

int retallades (Graf& g, int n) {
    priority_queue <arc, vector<arc>, greater<arc>> pq;
    vector<bool> vis (n, false);
    int suma = 0;
    int cont_v = 1; 

    vis[0] = true;
    for (arc uv : g[0]) pq.push (uv);

    while (not pq.empty()) {
        arc uv = pq.top();
        pq.pop();
        int coste = uv.first;
        int u = uv.second;
        if (not vis[u]) {
            vis[u] = true;
            suma += coste;
            ++cont_v;
            for (arc vi : g[u]) pq.push (vi);
        }
    }
    return suma;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        int total = 0;
        Graf G(n);

        for (int i = 0; i < m; ++i) {
            int x, y, c;
            cin >> x >> y >> c;
            total += c;
            G[x].push_back({c, y});
            G[y].push_back({c, x});
        }
        cout << total - retallades(G, n) << endl;
    }
}