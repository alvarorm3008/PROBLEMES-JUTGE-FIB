#include <iostream>

using namespace std;

int main(){
	
	cout.setf(ios::fixed);
	cout.precision(4);
    
	double n, sum = 0 ;
	cin >> n ;
	for(int i = 1; i<=n ; ++i){
		 sum += 1.0 / i;
	}
	cout << sum << endl ;
	
	return 0;
}
