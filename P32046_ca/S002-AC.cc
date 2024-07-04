#include <iostream>
using namespace std;
int main (){
	int x, n, xifres_x = 0, count = 0;
	cin >> x;
	xifres_x = x % 1000;
	cout << "nombres que acaben igual que " << x << ":" << endl;
	while (cin >> n) {
		if ((n % 1000) == xifres_x) {
			++count;
			cout << n << endl;
			
		}
	}
	cout << "total: " << count << endl;
	
}

