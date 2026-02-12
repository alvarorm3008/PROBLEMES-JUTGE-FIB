#include <iostream>

using namespace std;

int main(){
	
	int n, x, r = 0;
	cin >> n;
	x = n;
	
	while(x != 0){
			r += x % 10;
			x /= 100;
	}
	string b;
	if (r % 2 == 0) b = "";
	else b = " NOT";
	cout << n << " IS" << b << " COOL" << endl;
}
