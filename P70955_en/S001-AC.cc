#include <iostream>

using namespace std;

int main(){
	
int y , d , h , m , s , tot ;
cin >> y >> d >> h >> m >> s ;

y = y * 365 * 24 * 3600 ;
d = d * 24 * 3600 ;
h = h * 3600 ;
m = m * 60 ;
s = s ;
tot = y + d + h + m + s ;

cout << tot << endl;


	return 0;
}
