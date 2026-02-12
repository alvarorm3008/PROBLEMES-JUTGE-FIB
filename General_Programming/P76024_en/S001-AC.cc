#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
    cout.precision(4);
	
	double a, b, k;

	while (cin >> a >> b >> k) {
		double result = 0.0;
		for (double i = 0; (a + i * k) <= b; ++i) {
			result += 1.0 / (a + i * k);
		}
		cout << result << endl;
	}
}


