#include <iostream>

using namespace std;

int main(){
	
	int year ;
	cin >> year ;
	
	/* 
		multiplo de cuatro n1 % 4 = 0
	    leap years aquellos que son multiplos de 4 y no acaban con 2 ceros	
	    y los que acaban con dos ceros a los cuales si se los quitas el numero que te queda es divisible entre 4
	
	*/ 
	
	if (year != 1800 or year != 1900 or year != 2000) {
		if ((year % 4 == 0 or year % 100 == 0)){
			cout << "YES" << endl ;
		} else cout << "NO" << endl ;
		}
		
	else {
		if (year == 1800 or year == 1900) cout << "NO" << endl ;
		if (year == 2000) cout << "YES" << endl ;
	}
	
}
	

