#include <iostream>
using namespace std;

int main () {
	int x, count = 1;
	while (cin >> x) {
		int res;
		if (x % 2 == 0) res = count;
		++count;
	}
	cout << count << endl;
	}

