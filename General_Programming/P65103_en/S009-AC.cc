#include <iostream>
using namespace std;

int main() {
	int x, n, c = 1, k;
	bool found = false;
	cin >> n;
	while (cin >> x and not found) {
		if (c == n) {
			found = true;
			k = x;
		}
		c++;
	}
	if (found) cout << "At the position " << n << " there is a(n) " << k << "." << endl;
	else cout << "Incorrect position." << endl;
}
