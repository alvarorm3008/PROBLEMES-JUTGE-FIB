#include <iostream>

using namespace std;

int main(){
	
	int n, x;
	cin >> n;
	
	for(int b = 2; b <= 16; ++b){
		int count = 0;
		x = n;
		while(x != 0){
			x /= b;
			++count;
		}
		cout << "Base " << b << ": " << count << " cifras." << endl;
	}
	
	
	
	
	
	
	
}
