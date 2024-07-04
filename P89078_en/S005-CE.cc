#include <iostream>
using namespace std;

int main () {
	int x, count = 1, res;
	while (cin >> x) {
		if (x % 2 == 0) res = count;
		++count;
	}
	cout << res << endl;
	}

