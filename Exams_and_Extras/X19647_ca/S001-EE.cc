#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

const int infinit = INT_MAX;

typedef pair<int, int> arc;
typedef vector<vector<arc>> Grafo;
typedef vector<int> VI;
typedef vector<bool> VB;

int coste_min (const Grafo& G, const VI&costes, int a, int b, int n) {
    VI dist (n, infinit);
    VB vis (n, false);
    priority_queue <arc, vector<arc>, greater<arc>> PQ;
    dist[a] = 0;
    PQ.push ({0, a});

    while (not PQ.empty()) {
        arc act = PQ.top();
        PQ.pop();
        int u = act.second;
        if (not vis[u]) {
            vis[u] = true;
            if (u == b) return dist[u];
            for (arc uv : G[u]) { //adyacentes
                int c = uv.first;
                int v = uv.second;

                int dv = dist[u] + c; //distancia de A a v pasando por u
                if (v != b) dv += costes[v]; //si v es diferente de b sumamos el coste de pasar noche en v
                if (dist[v] > dv) {
                    dist[v] = dv;
                    PQ.push ({dv, v});
                }
            }
        }
    }
    return infinit;
}

int main () {
    int n, m;
    cin >> n >> m;
    VI costes (n);
    for (int i  = 0; i < n; ++i) cin >> costes[i];

    Grafo G(n);
    for (int i = 0; i < n; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        G[x].push_back({c, y});
        G[y].push_back({c, x});
    }

    int a, b;
    while (cin >> a >> b) {
        int c = coste_min (G, costes, a, b, n);
        cout << "c(" << a << ',' << b << ") = ";
        if (c == infinit) cout << "+oo" << endl;
        else cout << c << endl;
    }
}