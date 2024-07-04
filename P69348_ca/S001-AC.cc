#include <iostream>
#include <vector>
using namespace std;

void escribir(const vector<int>& v, int n) {
	cout << '(' << v[0];
	for (int i = 1; i < n; ++i) 
		cout << ',' << v[i];
	cout << ')' << endl;
}

void back(int i, int n, vector<int>& sol, vector<bool>& usat) {
	if (i == n) escribir(sol, n);
	else {
		for (int j = 0; j < n; ++j) {
			if (not usat[j]) {
				usat[j] = true;
				sol[i] = j+1;
				back(i+1, n, sol, usat);
				usat[j] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> sol(n);
	vector<bool> usat(n, false);
	
	back(0, n, sol, usat);
}
