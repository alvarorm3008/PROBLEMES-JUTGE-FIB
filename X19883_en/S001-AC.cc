#include <iostream>
using namespace std;

int main() {
	
    int n, res;
    while (cin >> n) {
        if (n < 0) {
            cout << ':';
            n = -n;
        }
        if (n == 0) cout << '-';
        while (n != 0) {
            res = n % 3;
            n /= 3;
            if (res == 1) cout << '+';
            if (res == 2) cout << '*';
            if (res == 0) cout << '-';
        }
        cout << endl;
    }
}
	
