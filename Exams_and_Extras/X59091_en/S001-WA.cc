#include <iostream>
using namespace std;

int main() {
	
	int f, c;
	bool n1 = true;
	
	
	while (cin >> f >> c){
		if (not n1) cout << endl;
		int n = 9;
		for (int j = 0; j < c; ++j){
			for (int i = 0; i < f; ++i){
				if (n == -1) n = 9;
				cout << n;
				--n;
				}
				cout << endl;
			}
			n1 = false;
		}
	}
	
