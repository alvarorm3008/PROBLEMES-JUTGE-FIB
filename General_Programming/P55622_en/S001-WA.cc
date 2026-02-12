#include <iostream>

using namespace std;

int main (){
	
	int n, ndigits = 0;
	
	while (cin >> n) {
		++ndigits;
		cout << "The number of digits of " << n << " is " << ndigits << endl;
	}
	return 0;
}
