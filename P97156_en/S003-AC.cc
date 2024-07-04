#include <iostream>

using namespace std ;

int main () {
	
	int x, y, a = 0, b = 0 ;
	cin >> x >> y ;
	
	if (x<=y){
		a = x ;
		b = y ;
		while (b>a){
		cout << a << "," ;
		++a;
	}
	cout << b << endl;
	} else {
		cout << "" << endl;
	}
	

return 0;
}


