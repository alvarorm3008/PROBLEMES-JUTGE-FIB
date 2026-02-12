#include <iostream>

using namespace std;

int main (){
	int n, ndigits = 0, x;
	cin >> n ;
	x = n ;
	if (x==0) ndigits = 1;
	else ndigits = 0;
	while (n != 0) {
		n /= 10;
		++ndigits;
	}
	
	cout << "The number of digits of " << x << " is " << ndigits << "." << endl;

	return 0;
}
