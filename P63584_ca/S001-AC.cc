#include <iostream>
#include <vector>
#include <map> 

using namespace std;

int k_esim(int k, const vector<vector<int> >& V) {
    map <int, int> m; //guarda <ele, pos de v
    
    int n = V.size();
    vector <int> num_vis (n, 1); //guarda el numero de elems visitados de cada vector

    //añadimos el primer elem de cada vector
    for (int i = 0; i < n; ++i) {
        if (not V[i].empty()) m.insert ({V[i][0], i});
    }

    for (int i = 0; i < k-1; ++i) {
        auto it = m.begin();
        int pos = it->second;
        m.erase(it);

        if (V[pos].size() > num_vis[pos]) {
            m.insert ({V[pos][num_vis[pos]], pos});
            ++num_vis[pos];
        }
    }
    return m.begin()->first;
}