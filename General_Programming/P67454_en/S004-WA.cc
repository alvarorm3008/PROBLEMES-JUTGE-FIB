#include <iostream>
using namespace std;

int main () {
	int count = 0;
	char  r;
	cin >> r;
	if (r == 'a') ++count;
	while (r != '.'){
		cin >> r;
		if (r == 'a') ++count;
		else if (r == '.') cout << count << endl;
	} 

	
	
	}

