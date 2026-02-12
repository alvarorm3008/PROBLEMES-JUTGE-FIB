#include <iostream>
#include <vector>
using namespace std;

int dues_monedes(int i, int x, int n, const vector<int>& mon, int suma, int s_max) {
	if (suma > x or suma + s_max < x) return 0;
	if (i == n) return 1;
	int cont = 0;
	for (int k = 0; k <= 2; ++k) {
		cont += dues_monedes(i+1, x, n, mon, suma + k*mon[i], s_max - 2*mon[i]);
	}
	return cont;
}

int main() {
	int x, n;
	
	while (cin >> x >> n) {
		vector<int> mon(n);
		int s_max = 0;
		for (int i = 0; i < n; ++i) {
			cin >> mon[i];
			s_max += mon[i];
		}
		
		cout << dues_monedes(0, x, n, mon, 0, 2*s_max) << endl;
	}
}
