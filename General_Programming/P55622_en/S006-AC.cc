#include <iostream>
using namespace std;

int main() {
	int x, res, n;
	cin >> x;
	n = x;
	if (x == 0) res = 1;
	else res = 0;
	while (x != 0) {
		x /= 10;
		++res;
	}
	cout << "The number of digits of "<< n << " is " << res <<  '.' << endl;
}
