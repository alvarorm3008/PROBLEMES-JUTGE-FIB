#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>


using namespace std;

const int infinit = INT_MAX;

typedef vector<vector<int>> Tablero;
typedef pair<int, int> pos;

int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};

bool borde (int x, int y, int n) {
    return x == 0 or x == n-1 or y == 0 or y == n-1;
}

int coste (Tablero& t, int n) {
    pos ini = {n/2, n/2};
    Tablero cost (n, vector<int> (n, infinit));
    Tablero quitada (n, vector<int> (n, 0));
    priority_queue <pair<int, pos>, vector<pair<int, pos>>, greater <pair<int, pos>>> q;
    cost[ini.first][ini.second] = t[ini.first][ini.second];
    q.push ({cost[ini.first][ini.second], ini});

    while (not q.empty()) {
        pos act = q.top().second;
        q.pop();
        if (not quitada[act.first][act.second]) {
            quitada[act.first][act.second] = 1;
            if (borde (act.first, act.second, n)) return cost[act.first][act.second];
            for (int i = 0; i < 4; ++i) {
                pos seg = {act.first + X[i], act.second + Y[i]};
                if (cost[act.first][act.second] + t[seg.first][seg.second] < cost[seg.first][seg.second]) {
                    cost[seg.first][seg.second] = cost[act.first][act.second] + t[seg.first][seg.second];
                    q.push({cost[seg.first][seg.second] ,seg});
                }
            }
        }

    }
    return -1;
    
}


int main () {
    int n;
    while (cin >> n) {
        Tablero t (n, vector<int> (n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cin >> t[i][j];
        cout << coste (t, n) << endl;
    }
}