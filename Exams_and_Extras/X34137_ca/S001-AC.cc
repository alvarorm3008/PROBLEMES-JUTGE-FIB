#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graf;

void dfs(const Graf& G, int u, vector<bool>& vis) {
	if (not vis[u]) {
		vis[u] = true;
		for (int v: G[u]) dfs(G, v, vis);
	}
}

int main() {
	int n, u, v, m;
	while (cin >> n >> u >> v >> m) {
		Graf G(n);
		Graf G_I(n);
		
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G_I[y].push_back(x);
		}
		
		vector<bool> vis(n, false);
		dfs(G, u, vis);
		if (not vis[v]) cout << 0 << endl;
		else {
			vector<bool> vis_I(n, false);
			dfs(G_I, v, vis_I);
			
			int cont = 0;
			for (int i = 0; i < n; ++i) {
				if (vis[i] and vis_I[i]) ++cont;
				//if (i != u and i != v and vis[i] and vis_I[i]) ++cont;
			}
			cout << cont-2 << endl; //cout << cont << endl;
		}
	}
}


