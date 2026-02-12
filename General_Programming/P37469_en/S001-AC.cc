#include <iostream>

using namespace std;

int main(){
	
int h , m  , s , n ;
cin >> n ;

h = n / 3600 ;
m = (n - 3600 * h) / 60 ;
s = n - 3600 * h - 60 * m ;

cout<< h << " " << m << " " << s << endl ;






	return 0;
}
