#include <iostream>
#include <vector>
using namespace std;

void escribir(const vector<int>& v, int n) {
	cout << v[0];
	for (int i = 1; i < n; ++i) cout << ' ' << v[i];
	cout << endl;
}

void zerosuns(int n, int u, vector<int>& sol, int i, int nu) {
	if (i == n) escribir(sol, n);
	else {
		//i-nu es el numero de ceros que llevo puestos
		//n-u es el numero de ceros que puedo poner en total
		if (i - nu < n - u) {
			sol[i] = 0;
			zerosuns(n, u, sol, i+1, nu);
		}
		if (nu < u) {
			sol[i] = 1;
			zerosuns(n, u, sol, i+1, nu+1);
		}
	}
}

int main() {
	int n, u;
	cin >> n >> u;
	
	vector<int> sol(n);
	zerosuns(n, u, sol, 0, 0);
}
