#include <iostream>

using namespace std;

int main () {
	
	int n;
	while (cin >> n){
			int rem = 0;
			cout << "The sum of the digits of " << n << " is ";
			while (n != 0){
				rem += n % 10;
				n /= 10;
			}
			cout << rem << "." << endl;
	}
	
	
}
