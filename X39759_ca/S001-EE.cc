#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> Tablero;
typedef pair<int, int> Pos;

const int X[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int Y[8] = {-1,  1, 2, 2, 1, -1, -2, -2};

bool pos_valida (int n, int m, int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

int buscar_obj (const Pos& ini, const Pos& fin, int n, int m) {
    if (ini == fin) return 0;
    queue<Pos> Q;
    Tablero dist (n, vector<int> (m, -1));
    Q.push(ini);
    dist[ini.first][ini.second] = 0;
    while (not Q.empty()) {
        Pos act = Q.front();
        Q.pop();
        for (int i = 0; i < 8; ++i) {
            int x = act.first + X[i];
            int y = act.second + Y[i];
            if (pos_valida(x, y, n, m) and dist[x][y] == -1) {
                dist[x][y] = dist[act.first][act.second] + 1;
                if (Pos(x, y) == fin) return dist[x][y];
                Q.push({x, y}); 

            }
        }

    }
    return -1;
}

int puntos_max (const vector<Pos>& obj, int n, int m, int W, int L, int k) {
    int max = 0;
    int puntos = 0;
    int i = 0;
    bool fin = false;

    while (i < k and not fin) {
        int dist = buscar_obj (obj[i], obj[i+1], n, m);
        //no llego
        if (dist == -1) fin = true;
        else {
            puntos = W - (dist*L);
        }
    }
    return max;
}

int main () {
    int n, m, W, L, k;
    while (cin >> n >> m >> W >> L >> k) {
        vector<Pos> obj (k+1);
        obj[0] = {0, 0};
        for (int i = 1; i <= k; ++i ) {
            cin >> obj[i].first >> obj[i].second;
        }
        cout << puntos_max (obj, n, m, W, L, k);
    }
}