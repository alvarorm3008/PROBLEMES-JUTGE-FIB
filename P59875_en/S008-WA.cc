#include <iostream>

using namespace std ;

int main () {
	
	int x, y, a, b ;
	cin >> x >> y ;
	
	if (x>=y){
		a = x ;
		b = y ;
	} else {
		a = y ;
		b = x ;
	}
	while (a>b){
		cout << a << endl;
		--a;
	}
	while (b>a){
		cout << b << endl;
		--b;
	}

return 0;
}


