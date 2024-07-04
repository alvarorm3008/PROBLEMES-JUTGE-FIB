#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef vector<vector<int>> Graph;
typedef vector<string> VS;
typedef map<string,int> Map;
typedef vector<int> VI;

queue<string> topologica(const Graph& G, Map& pos, const VS& nom, VI& ge) {
	int n = G.size();
	queue<string> orden;
	priority_queue<string, vector<string>, greater<string>> PQ;
	for (int i = 0; i < n; ++i) 
		if (ge[i] == 0) PQ.push(nom[i]);
	
	while (not PQ.empty()) {
		string u = PQ.top();
		PQ.pop();
		orden.push(u);
		
		for(int pv: G[pos[u]]) {
			--ge[pv];
			if (ge[pv] == 0) PQ.push(nom[pv]);
		}
	}
	return orden;
}

int main() {
	int n;
	while (cin >> n) {
		VS nom(n);
		Map pos;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			nom[i] = s;
			pos[s] = i; // pos.insert({s, i});
		}
		Graph G(n);
		VI ge(n, 0);
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			string u, v;
			cin >> u >> v;
			/*auto it1 = pos.find(u);
			auto it2 = pos.find(v);
			G[it1->second].push_back(it2->second);*/
			G[pos[u]].push_back(pos[v]);
			++ge[pos[v]]; //++ge[it2->second];
		}
		
		queue<string> orden = topologica(G, pos, nom, ge);
		
		if (orden.size() != n) cout << "NO VALID ORDERING" << endl;
		else {
			while (not orden.empty()) {
				cout << orden.front();
				orden.pop();
			}
			cout << endl;
		}
	}
}
