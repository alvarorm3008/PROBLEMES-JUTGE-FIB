#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	cout.setf(ios::fixed);
	cout.precision(6);
	int n;
	double x, y, r;
	cin >> n;
	for(int i=0; i<n; ++i){
		string forma;
		cin >> forma;
		double  x, y, r;
	 if (forma == "rectangle"){
		cin >> x >> y ;
		cout << x * y << endl;
	} else {
		cin >> r;
		cout << r * r * M_PI << endl;
	}
}

	
}
