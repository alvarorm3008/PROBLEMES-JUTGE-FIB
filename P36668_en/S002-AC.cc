#include <iostream>
using namespace std;

int main() {
	int x, res = 0;
	cin >> x;
	for (int i = 1; i <= x; ++i) {
		res += i*i;
	}
	cout << res << endl;
}
