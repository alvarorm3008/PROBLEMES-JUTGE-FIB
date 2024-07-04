#include <iostream>

using namespace std;

int main () {
	
	int n, rem = 0;
	while (cin >> n){
			cout << "The sum of the digits of " << n << " is ";
			while (n != 0){
				rem += n % 10;
				n /= 10;
			}
			cout << rem << "." << endl;
	}
	
	
}
