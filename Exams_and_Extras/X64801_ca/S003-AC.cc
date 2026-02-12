#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
typedef vector<vector<int>> Grafo;

bool dfs (const Grafo& G, int u) {
	int n = G.size();
	stack<int> S;
	vector<bool> vis(n, false);
	S.push(u);
	vis[u] = true;
	
	while (not S.empty()) {
		int v = S.top();
		S.pop();
		//adyacentes
		for (int w: G[v]) {
			if (u == w) return true;
			if (not vis[w]) {
				vis[w] = true;
				S.push(w);
			}
		}
	}
	return false;
}

bool es_ciclic(const Grafo& G) {
	int n = G.size();
	
	for (int u = 0; u < n; ++u) {
		if (dfs(G, u)) return true;
	}
	return false;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        Grafo g(n);
		       
        int x,y;
        for (int i = 0; i < m; ++i){
            cin >> x >> y;
            g[x].push_back(y); // x es adyacente a y
        }
        
        cout << (es_ciclic(g) ? "yes" : "no") << endl;
    }
}