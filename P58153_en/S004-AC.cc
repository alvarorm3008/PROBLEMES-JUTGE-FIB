#include <iostream>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(10);
	
	int n, m;
	
	while (cin >> n >> m){
		double sum1 = 0.0;
		for(double i = m + 1; i<=n ; ++i){
				sum1 += 1.0 / i;
		}
		cout << sum1<< endl;
	}
}


