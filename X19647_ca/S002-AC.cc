#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> //climits
using namespace std;

typedef pair<int, int> Arc; //first = distancia, second = vertice
typedef vector<vector<Arc>> Grafo;
typedef vector<int> VI;
typedef vector<bool> VB;

const int infinit = INT_MAX; //1e9

int coste_min(const Grafo& G, const VI& costes, int a, int b, int n) {
	VI dist(n, infinit);
	VB vis(n, false);
	priority_queue<Arc, vector<Arc>, greater<Arc>> PQ;
	dist[a] = 0;
	PQ.push({0, a});
	
	while (not PQ.empty()) {
		Arc act = PQ.top();
		PQ.pop();
		
		int u = act.second;
		if (not vis[u]) {
			vis[u] = true;
			if (u == b) return dist[u];
			for (Arc uv: G[u]) { //adyacentes
				int c = uv.first;
				int v = uv.second;
				
				int dv = dist[u] + c; //la distancia de a a v pasando por u
				if (v != b) dv += costes[v]; //si v != b sumamos el coste de pasar noche en v
				if (dist[v] > dv) {
					dist[v] = dv;
					PQ.push({dv, v});
				}
			}
		}
	}
	return infinit;
}

int main() {
	int n, m;
	cin >> n >> m;
	VI costes(n);
	for (int i = 0; i < n; ++i) cin >> costes[i];
	
	Grafo G(n);
	for (int i = 0; i < m; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		G[x].push_back({c, y});
		G[y].push_back({c, x});
	}
	
	int a, b;
	while (cin >> a >> b) {
		int c = coste_min(G, costes, a, b, n);
		cout << "c(" << a << ',' << b << ") = ";
		if (c == infinit) cout << "+oo" << endl;
		else cout << c << endl;
	}
}


