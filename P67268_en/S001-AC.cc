#include <iostream>
#include <vector>
using namespace std;

int main() {
	int x;
	while (cin >> x) {
		vector <int>algo(x);
		bool first = true;
		for (int i = 0; i < x; i++) {
			cin >> algo[i];
		}

		for (int i = x - 1; i >= 0; i--) {
			if (not first) cout << ' ';
			first = false;
			cout << algo[i];
		}
		cout << endl;
	}
}
