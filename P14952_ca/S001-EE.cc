#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph;

void ord_top (const Graph& g, vector<int>& ge, vector<int>& orden) {
    priority_queue <int, vector<int>, greater<int>> pq;
    int n = g.size();

    for (int i = 0; i < n; ++i) 
        if (ge[i] == 0) pq.push(i);
    while (not pq.empty()) {
        int u = pq.top();
        pq.pop();
        orden.push_back(u);
        for (int v: g[u]) {
            if (--ge[v] == 0) pq.push(v);
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Graph g(n);
        vector<int> ge (n, 0);
        int x, y;
        for (int i = 0; i < 4; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
            ++ge[i];
        }
        vector <int> orden;
        ord_top(g, ge, orden);

        for (int i = 0; i < n; ++i) {
            if (i != 0) cout << ' ';
            cout << orden[i];
        }
        cout << endl;
    }
}