#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<string>> Mapa;
typedef vector<vector<int>> Mapa_dist;
typedef pair<int, int> Pos;

const vector<Pos> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool pos_ok(int x, int y, int n, int m) {
	return x >= 0 and x < n and y >= 0 and y < m;
}

int distancia(const Mapa& mapa, Pos ini, Pos fin) {
	if (ini == fin) return 0;
	int n = mapa.size();
	int m = mapa[0].size();
	Mapa_dist dist(n, vector<int>(m, -1));
	queue<Pos> Q;
	Q.push(ini);
	dist[ini.first][ini.second] = 0;
	
	while (not Q.empty()) {
		Pos act = Q.front();
		Q.pop();
		
		for (int i = 0; i < 4; ++i) {
			Pos next = {act.first + dir[i].first, act.second + dir[i].second};
			int x = next.first;
			int y = next.second;
			if (pos_ok(x, y, n, m) and mapa[x][y] != "*" and dist[x][y] == -1) {
				dist[x][y] = dist[act.first][act.second] + 1;
				if (next == fin) return dist[x][y];
				Q.push(next);
			}
		}
	}
	return -1;
}

Pos buscar_par(const Mapa& mapa, const string& s) {
	int n = mapa.size();
	int m = mapa[0].size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
			if (mapa[i][j] == s) return Pos(i, j);
	}
	return Pos(-1, -1);
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Mapa mapa(n, vector<string>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cin >> mapa[i][j];
		}
		
		int p;
		cin >> p;
		vector<string> par(p);
		for (int i = 0; i < p; ++i) cin >> par[i];
		
		vector<Pos> posi(p+1);
		posi[0] = {0, 0};
		bool fin = false;
		
		for (int i = 0; i < p; ++i) {
			posi[i+1] = buscar_par(mapa, par[i]);
			if (posi[i+1] == Pos(-1, -1)) fin = true;
		}
			
		int total = 0;
		int i = 0;
		
		while (not fin and i < p) {
			int dist = distancia(mapa, posi[i], posi[i+1]);
			if (dist == -1) fin = true;
			else total += dist; //total += dist + 1; 
			++i;
		}
		if (not fin) cout << total + p << endl;
		else cout << "imposible" << endl;
	}
}

