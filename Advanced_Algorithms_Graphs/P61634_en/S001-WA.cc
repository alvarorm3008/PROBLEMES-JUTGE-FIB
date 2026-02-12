#include <iostream>

using namespace std;

int main(){
	
int y1 ;

cin >> y1 ;
if (y1 != 2000) {
	if (((y1 / 100) / 4) == 1) cout << "YES" ;
	else cout << "NO" ;	
} else cout << "YES" ;

	return 0;
}
