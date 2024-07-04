#include <iostream>

using namespace std;

int main(){
	
	int count = 0;
	char  r;
	while (r != '.'){
		cin >> r;
		if (r == 'a') ++count;
	} 
	cout << count << endl;
}
