#include <iostream>

using namespace std ;

int main () {
	
	int x, y, a, b ;
	cin >> x >> y ;
	
	if (x>=y){
		a = x ;
		b = y;
		while (a>=b){
		cout << a << endl;
		--a;
	}
	} else while (a<=b){
		cout << b << endl;
		--b;
	} if (y<=x) {
		a = y ;
		b = x ;
		while (a>=b){
		cout << a << endl;
		--a;
	}
	} else while (a<=b){
		cout << b << endl;
		--b;
	}

return 0;
}

