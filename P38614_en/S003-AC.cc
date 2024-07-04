#include <iostream>

using namespace std;

int main(){
	
	int n, r, x, suma = 0;
	cin >> n;
	x = n;
	while(x != 0){
		r = x % 10;
		x /= 100;
		suma += r;					
	}
	if (suma % 2 == 0) cout << n << " IS COOL" << endl;
	else cout << n << " IS NOT COOL" << endl;	
}
