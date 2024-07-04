#include <iostream>
using namespace std;

bool is_palindromic (int n){
	int n1, n2 = 0, rem = 0;
	n1 = n;
	while (n != 0) {
		rem = n % 10;
		n /= 10;
		n2 = rem + (n2 * 10);
	}
	if (n1 == n2) return true;
	else return false;
}
