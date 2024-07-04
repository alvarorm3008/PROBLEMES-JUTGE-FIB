#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

typedef vector<vector<int>> Graf;
const int infinit = INT_MAX; //1e9

int num_vertex(const Graf& G, int u, vector<bool>& vis) {
	//if (not vis[u]) {
		vis[u] = true;
		int num = 1;
		for (int v: G[u]) {
			if (not vis[v])
				num += num_vertex(G, v, vis);
		}
		return num;
	//}
	//return 0;
}

pair<int,int> comp_connexes(const Graf& G) {
	int n = G.size();
	vector<bool> vis(n, false);
	pair<int, int> res(infinit, -1);
	
	for (int u = 0; u < n; ++u) {
		if (not vis[u]) {
			int num = num_vertex(G, u, vis);
			if (res.first > num) res.first = num;
			if (res.second < num) res.second = num;
		}
	}
	return res;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Graf G(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		
		pair<int,int> p = comp_connexes(G);
		cout << p.first << ' ' << p.second << endl;
	}
}