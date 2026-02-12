#include <iostream>
using namespace std;

int main() {
	
	int n;
	bool primer = true;
	
	while (cin >> n) {
		if (not primer) cout << endl;
		primer = false;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cout << n;
			}
			cout << endl;
		}
		cout << endl;
	}
}
