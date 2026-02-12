#include <iostream>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(10);
	
	int n, m;
	
	while (cin >> n >> m){
		double sum1 = 0.0, sum2 = 0.0;
			for(double i = 1; i<=n ; ++i){
				sum1 += 1.0 / i;
			}
			for(double j = 1; j <= m; ++j){
				sum2 += 1.0 / j;
			}
		cout << sum1 - sum2 << endl;
	}
}


