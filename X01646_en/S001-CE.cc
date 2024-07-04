#include <iostream>

using namespace std;

int main () {
	
	int b, x, s;
	cin >> b;
	s = x;
	
	while (cin >> x){
		int dig = 0;
			cout << x << ": ";
		
			while (x > 0){
     			dig += x % b;    
				x /= b;
    		}
    		cout << dig << endl;
	}	
}


