#include <iostream>
using namespace std;

bool c_frac(int n1, int d1, int n2, int d2) {
	if ((n1 * d2) < (n2 * d1)) return true;
	else return false;
}

int main() {
	int a, b, c, d;
	
	while (cin >> a >> b >> c >> d) cout << (c_frac(a, b, c, d) ? "yes" : "no") << endl;
}
