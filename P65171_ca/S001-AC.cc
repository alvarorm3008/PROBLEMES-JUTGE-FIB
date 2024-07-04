#include <iostream>
using namespace std;

int main () {
	
	cout.setf(ios::fixed);
    cout.precision(2);
     
	double n, suma = 0, suma2 = 0, suma3 = 0, suma4 = 0;
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		double x;
		cin >> x;
		suma = x * x;
		suma2 += suma;
		suma3 += x;
		suma4 = suma3 * suma3;	
	}
	cout << (1 / (n - 1)) * suma2 - (1 / (n * (n - 1))) * suma4 << endl;
}
