#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

void escriu(const VI& v, int n) {
	cout << '(';
	for (int i = 0; i < n; ++i) {
		if (i != 0) cout <<',';
		cout << v[i];
	}
	cout << ')' << endl;
}

bool pou(const VI& v, int i, int j) {
	return i >= 2 and v[i-2] + j + 1 > 2*v[i-1];
}

void seq_sense_pous(int i, VI& sol, VB& vis, int n) {
	if (i == n) escriu(sol, n);
	else {
		for (int j = 0; j < n; ++j) {
			if (not vis[j] and not pou(sol, i, j)) {
				sol[i] = j+1;
				vis[j] = true;
				seq_sense_pous(i+1, sol, vis, n);
				vis[j] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	VI sol(n);
	VB vis(n, false);
	
	seq_sense_pous(0, sol, vis, n);
}