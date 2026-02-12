#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graf;
typedef vector<int> VI;
typedef pair<int, int> pos;

void escriure (int n, int m, const VI& v ) {
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << v[i];
    }
}

void bfs (Graf& g, VI& sol, int n, int m) {
    queue<int> q;
    vector<bool> vis (n, false);

    
    for (int u = 0; u < n; ++u) {
        if (not vis[u]) {
            q.push(u);
            vis[u] = true;
            while (not q.empty()) {
                int v = q.front();
                q.pop();
                for (int w : g[v]) {
                    if (not vis[w]) {
                        q.push(w);
                        vis[w] = true;
                    }
                }
            }
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graf g(n, VI (m));
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
        }
        VI sol;
        bfs (g, sol, n, m);
        escriure (n, m, sol);
        
    }
}