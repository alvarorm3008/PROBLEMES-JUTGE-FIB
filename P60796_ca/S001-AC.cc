#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pos;
typedef vector<vector<char>> Mapa;

const int X[4] = {-1, 0, 1, 0};
const int Y[4] = {0, 1, 0, -1};

//const vector<Pos> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool pos_valida(const Mapa& mapa, int x, int y) {
	int n = mapa.size();
	int m = mapa[0].size();
	return x >= 0 and x < n and y >= 0 and y < m and mapa[x][y] != 'X';
}

int bfs(Mapa& mapa, int f, int c) {
	queue<pair<Pos, int>> Q; // el int es la distancia de Pos a {f, c}
	Q.push({{f, c}, 0});
	mapa[f][c] = 'X';
	
	while (not Q.empty()) {
		Pos act = Q.front().first;
		int dist = Q.front().second;// es la distanci de act a {f, c}
		Q.pop();
			
		for (int i = 0; i < 4; ++i) {
			int x_seg = act.first + X[i]; //act.first + dirs[i].first;
			int y_seg = act.second + Y[i]; //act.second + dirs[i].second;
			if (pos_valida(mapa, x_seg, y_seg)) { //es valida y no es X
				if (mapa[x_seg][y_seg] == 't') return dist + 1;
				else {
					mapa[x_seg][y_seg] = 'X';
					Q.push({{x_seg, y_seg}, dist+1});
				}
			}
		}
	}
	return -1;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	Mapa mapa(n, vector<char>(m));
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j)
			cin >> mapa[i][j];
			
	int f, c;
	cin >> f >> c;
	int dist = bfs(mapa, f-1, c-1);
	if (dist == -1) cout << "no es pot arribar a cap tresor" << endl;
	else cout << "distancia minima: " << dist << endl;	
}


