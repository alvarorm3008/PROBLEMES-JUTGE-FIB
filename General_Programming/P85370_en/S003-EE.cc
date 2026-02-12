#include <iostream>
#include <cmath>

using namespace std;

int main () {
	cout.setf(ios::fixed);
	cout.precision(4);
	
	double c, i, t, resultado = 1;
	string ch;
	cin >> c >> i >> t >> ch;
	
	if (ch == "simple") {
        resultado = c + c * (i/100) * t;
        cout << resultado << endl;
    }
	else {
       for (int j = 1; j <= t; ++i) {
           resultado *= 1 + i/100;
           cout << c*resultado << endl;
    } 
    }
}
