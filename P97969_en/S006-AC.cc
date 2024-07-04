#include <iostream>

using namespace std;

int main(){
	
	int count;
	char  r;
	cin >> r;
	if (r == 'a') count = 1;
	else count = 0;
	while (r != '.'){
		cin >> r;
		if (r == 'a') ++count;
	} 
	cout << count << endl;
}
