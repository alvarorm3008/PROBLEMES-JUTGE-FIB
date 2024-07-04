#include <iostream>

using namespace std;

int main () {
	
	int d, n, t, a, r = 0, count = 0;
	cin >> d >> n >> t;
	
	for (int i = 0; i < t; ++i){
		cin >> a;
		r = r + a - d;
		if (r + n > 0) ++ count;
	}
	cout << count << endl;
	
	
	
	
	
}
