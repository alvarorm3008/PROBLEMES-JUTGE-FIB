#include <iostream>
using namespace std;

bool c_frac(int n1, int d1, int n2, int d2) {
	if (d1 == d2) {
		if (n1 < n2) return true;
		else return false;
	}
	else if (n1 == n2) {
		if (d1 < d2) return true;
		else return false;
	}
	else if (n1 != n2 and d1 != d2) {
	if ((n1 / d1) < (n2 / d2)) return true;
	else return false;
	}
}

int main() {
	int a, b, c, d;
	
	while (cin >> a >> b >> c >> d) cout << (c_frac(a, b, c, d) ? "yes" : "no") << endl;
}
