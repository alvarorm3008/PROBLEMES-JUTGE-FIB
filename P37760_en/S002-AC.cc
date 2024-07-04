#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	cout.setf (ios::fixed);
	cout.precision (6);
	
	double n;
	
	while (cin >> n){
		n *= M_PI / 180;	
		cout << sin (n) << " " << cos (n) << endl;
	}
	
}
