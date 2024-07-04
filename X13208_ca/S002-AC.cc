#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

typedef vector<vector<int>> Tablero;
typedef pair<int, int> pos;

const int infinit = INT_MAX;

const int X[4] = {-1, 0, 1, 0};
const int Y[4] = {0, 1, 0, -1};

bool borde (int n, pos& act) {
    return act.first == 0 or act.first == n-1 or act.second == 0 or act.second == n-1;
}

int bfs (Tablero& t, int n) {
    pos ini = {n/2, n/2};
    Tablero coste (n, vector<int> (n, infinit));
    Tablero quitada (n, vector<int> (n, 0));
    priority_queue <pair<int, pos>, vector<pair<int, pos>>, greater <pair<int, pos>>> pq;
    coste[ini.first][ini.second] = t[ini.first][ini.second];
    pq.push ({coste[ini.first][ini.second], ini});

    while (not pq.empty()) {
        pos act = pq.top().second;
        pq.pop();
        quitada[act.first][act.second] = 1;
        if (borde (n, act)) return coste[act.first][act.second];
        else {
            for (int i = 0; i < 4; ++i) {
                pos next = {act.first + X[i], act.second + Y[i]};
                if (coste[act.first][act.second] + t[next.first][next.second] < coste [next.first][next.second]) {
                    coste [next.first][next.second] = coste [act.first][act.second] + t[next.first][next.second];
                    pq.push ({coste[next.first][next.second], next});
                }
            }
        }

    }
    return -1;
}

int main () {
    int n;
    while (cin >> n) {
        Tablero t(n, vector<int> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> t[i][j];
            }
        }
        cout << bfs (t, n) << endl;
    }
}