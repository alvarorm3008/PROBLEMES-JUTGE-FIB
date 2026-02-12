#include <iostream>

using namespace std;

int main (){
	int n, ndigits ;
	
	cin >> n ;
	
	while (n != 0) {
		n /= 10;
		++ndigits;
	}
	
	cout << "The number of digits of " << n << " is " << ndigits << "." << endl;

	return 0;
}
