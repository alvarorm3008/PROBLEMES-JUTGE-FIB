#include <iostream>

using namespace std;

int main() {
    int base, n, x;
    cin >> base;
    while (cin >> n) {
        x = n;
        int res = 0;
        while (n != 0) {
            res += n % base;
            n /= base;
        }

    cout << x << ": " << res << endl;
    }
}
