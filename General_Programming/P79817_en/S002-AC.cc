#include <iostream>
#include <cmath>

using namespace std;

int main () {
	
	int a, b, resultado;
	while (cin >> a >> b){
		if (b == 0) resultado = 1;
		else if (a == 0) resultado = 0;
		else resultado = pow (a,b);
		cout << resultado << endl;
	}	
	
}
