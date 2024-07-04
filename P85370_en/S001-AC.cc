#include <iostream>
#include <cmath>

using namespace std;

int main () {
	cout.setf(ios::fixed);
	cout.precision(4);
	
	double c, i, t, resultado = 0;
	string ch;
	cin >> c >> i >> t >> ch;
	
	if (ch == "simple") resultado = c + c * (i/100) * t;
	else resultado = c * pow(1 + (i / 100),t);
	
	cout << resultado << endl;

	
	
	
	
	
	
	
}
