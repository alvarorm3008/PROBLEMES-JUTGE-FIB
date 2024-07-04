#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<bool> VB;

void escribir(VS& par, VI& sol, int n) {
	cout << '(' << par[sol[0]];
	for (int i = 1; i < n; ++i) 
		cout << ',' << par[sol[i]];
	cout << ')' << endl;
}

void permutacio(int i, int n, VS& par, VI& sol, VB& usat) {
	if (i == n) escribir(par, sol, n);
	else {
		for (int j = 0; j < n; ++j) {
			if (not usat[j]) {
				usat[j] = true;
				sol[i] = j;
				permutacio(i+1, n, par, sol, usat);
				usat[j] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	VS par(n);
	for (int i = 0; i < n; ++i) cin >> par[i];
	
	VB usat(n, false);
	VI sol(n);
	
	permutacio(0, n, par, sol, usat);
}
