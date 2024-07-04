#include <iostream>

using namespace std;

int main(){
	int count = 0;
	char  r;
	while (r != '.'){
		cin >> r;
		if (r == 'a') ++count;
	} 
	if (count >= 1) cout << "yes" << endl;
    else cout << "no" << endl;

	
	
	return 0;
}
