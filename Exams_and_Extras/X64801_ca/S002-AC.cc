#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<vector<int>> Graf;

bool topo (const Graf&g, int n, int m) {
    vector<int> ge (n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) ++ge[v];
    }
    vector<int> cands;
    for (int u = 0; u < n; ++u) {
        if (ge[u] == 0) cands.push_back(u);
    }
    while (not cands.empty()) {
        int u = cands.back();
        cands.pop_back();
        --n;
        for (int v : g[u]) {
            --ge[v];
            if (ge[v] == 0) cands.push_back(v);
        }
    }
    return n > 0;
}

int main () {
    int n, m;
    while (cin >> n) {
        int m;
        cin >> m;
        Graf g (n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
        }
        cout << ((topo(g, n, m) ? "yes" : "no")) << endl;
    }
}