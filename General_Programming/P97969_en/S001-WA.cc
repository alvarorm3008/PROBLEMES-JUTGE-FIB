#include <iostream>

using namespace std;

int main(){
	
	int count = 0;
	char  r;
	cin >> r;
	
	
	while (r != '.'){
		cin >> r;
		if (r == 'a') ++count;
	}
	cout << count << endl;

	
	
	
	
	
	return 0;
}
