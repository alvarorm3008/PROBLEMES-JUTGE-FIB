#include <iostream>
using namespace std;

int main() {
	
	int n, suma1 = 0, suma2 = 0, suma = 0;
	char r;
	cin >> n;
	
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> r;
			if ((i + j) == n - 1) suma1 += r - '0';
			if (i == j) suma2 += r - '0';
		}
	}
	suma = suma1 + suma2;
	cout << suma << endl;
	
}
