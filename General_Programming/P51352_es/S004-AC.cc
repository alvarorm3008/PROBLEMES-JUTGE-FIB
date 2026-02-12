#include <iostream>

using namespace std;

int main(){
	
char n1 , n2 ;	

cin >> n1 >> n2 ;

if (n1 == 'A') {
	if (n2 == 'A') cout << "-" << endl ;
	if (n2 == 'P') cout << "1" << endl ;
	if (n2 == 'V') cout << "2" << endl ;
} else if (n1 == 'P') {
	if (n2 == 'P') cout << "-" << endl ;
	if (n2 == 'V') cout << "1" << endl ;
	if (n2 == 'A') cout << "2" << endl ;
} else if (n1 == 'V') {
	if (n2 == 'V') cout << "-" << endl ;
	if (n2 == 'A') cout << "1" << endl ;
	if (n2 == 'P') cout << "2" << endl ;
}

}
