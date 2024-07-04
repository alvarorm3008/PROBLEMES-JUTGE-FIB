#include <iostream>
#include <vector>
using namespace std;

int num_inv(vector<int>& v, int e, int m, int d) {
	vector<int> aux(d-e+1);
	int i = e, j = m+1, k = 0;// i recorre v[e..m], j recorre v[m+1..d], k recorre aux
	int cont = 0;
	
	while (i <= m and j <= d) {
		if (v[i] <= v[j]) aux[k++] = v[i++];
		else {
			aux[k++] = v[j++];
			cont += m-i+1;
		}
	}
	
	//añadir v[i..m]
	while (i <= m) aux[k++] = v[i++];
	
	//añadir v[j..d]
	while (j <= d) aux[k++] = v[j++];
	
	//copiar aux en v
	for (int i = 0; i < int(aux.size()); ++i) v[e+i] = aux[i];
	return cont;
}

int inversions(vector<int>& v, int e, int d) {
	if (e < d) {
		int m = (e+d)/2;
		int x1 = inversions(v, e, m);
		//HI1: x1 es el num. inversions de v[e..m]
		int x2 = inversions(v, m+1, d);
		//HI2: x2 es el num. inversions de v[m+1..d]
		return x1 + x2 + num_inv(v, e, m, d);
	}
	return 0;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		
		cout << inversions(v, 0, n-1) << endl;
	}
}
