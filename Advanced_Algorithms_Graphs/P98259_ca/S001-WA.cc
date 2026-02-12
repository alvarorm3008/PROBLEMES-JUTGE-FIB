#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

const int infinit = INT_MAX;

typedef vector<vector<char>> Tablero;
typedef pair<int, int> pp; //passos i persones

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1};

bool pos_valida (int n, int m, int x, int y, const Tablero& t) {
    return x >= 0 and y >= 0 and x < n and y < m and t[x][y] != '#';
}

pair<int, int> bfs (Tablero& t) {
    if (t[0][0] == 'T') return {0, 0};
    int n = t.size();
    int m = t[0].size();
    vector<vector<pair<int, int>>> dist (n, vector<pair<int, int>> (m, {infinit, 0})); 
    queue<pp> q;
    q.push ({0, 0});
    dist[0][0].first = 0;
    dist[0][0].second = (t[0][0] == 'P');
    int pers = 0;
    int distancia = 0;

    while (not q.empty()) {
        pp act = q.front();
        q.pop();
        int f = act.first;
        int c = act.second;
        if (t[f][c] == 'T') return dist[f][c];
        for (int i = 0; i < 4; ++i) {
            int x_seg = x[i] + f;
            int y_seg = y[i] + c;
            if (pos_valida (n, m, x_seg, y_seg, t)) {
                pers = dist[f][c].second + (t[x_seg][y_seg] == 'P');
                if (dist[x_seg][y_seg].first == infinit) {
                    distancia = dist[f][c].first + 1;
                    dist[x_seg][y_seg].first = distancia;
                    dist[x_seg][y_seg].second = pers;
                    q.push({x_seg, y_seg});
                }
                else if (dist [x_seg][y_seg].first == distancia and dist[x_seg][y_seg].second < pers)
                    dist[x_seg][y_seg].second = pers;
            }
        }
    }
    return {infinit, 0};
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Tablero t (n, vector<char> (m));
        bool telecos = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >>t[i][j];
                if (t[i][j] == 'T') telecos = true;;
            }
        }
        if (not telecos) cout << "El telecos ha fugit." << endl;
        else {
            pp p = bfs (t);
            if (p.first == infinit) cout << "El telecos esta amagat" << endl;
            else {
                cout << p.first << ' ' << p.second << endl;
            }
        }
    }
}
