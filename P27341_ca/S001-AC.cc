#include <iostream>
#include <cmath>

using namespace std;

int main (){
	
	int a, b;
	
	while (cin >> a >> b){
		int r = 0;
		for (int i = a; i <= b; ++i){
		
			r += pow(i,3);
		}
		cout << "suma dels cubs entre " << a << " i " << b << ": " << r << endl;
	}	
}

