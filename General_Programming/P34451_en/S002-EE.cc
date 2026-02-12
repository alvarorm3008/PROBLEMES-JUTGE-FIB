#include <iostream>

using namespace std;

int main(){
	
	int x, n, count = 0;
	cin >> x >> n;
	
	while (cin >> x){
		if (n % x == 0){
			++count;
	} 
	}
	cout << count << endl;
	
	
	
	
	
}
