#include <iostream>
using namespace std;

int main () {
	bool trobat = false;
	char  r;
	cin >> r;
	while (r != '.'){
		if (r == 'a') trobat = true;
		cin >> r;
	} 
	if(trobat) cout << "yes" << endl;
	else cout << "no" << endl;
	}

