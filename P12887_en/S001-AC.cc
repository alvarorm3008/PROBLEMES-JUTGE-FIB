#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int, int> ArcP;       //arco con pesos
typedef vector<vector<ArcP> > GrafP;    //grafo con pesos

int MST (const GrafP& G) { 
   int n = G.size();
   priority_queue<ArcP, vector<ArcP>, greater<ArcP> > CP;
   vector<bool> visto(n,false); // indica los v�rtices vistos
   visto[0] = true; 	
   
   for (int i = 0; i < G[0].size(); ++i) CP.push(G[0][i]);
   int c = 1;  //indica el n�mero de v�rtices visitados
   int s = 0; //indica el coste del MST

   while (c != n) { 
      int coste = CP.top().first; 
      int v = CP.top().second; 
      CP.pop();
      if (not visto[v]) {
         for (int i = 0; i < G[v].size(); ++i) {
         	ArcP uv = G[v][i];
            if (not visto[uv.second]) CP.push(uv); 	
         }
         visto[v] = true;
         ++c;
         s += coste;
      }
   }
   return s;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        GrafP G(n);
        int u, v, w;
     	for (int i = 0; i < m; ++i) {
        	cin >> u >> v >> w;
        	G[u-1].push_back(make_pair(w,v-1));
        	G[v-1].push_back(make_pair(w,u-1));
    	}
        int suma = MST(G);
        cout << suma << endl;
    }
}
