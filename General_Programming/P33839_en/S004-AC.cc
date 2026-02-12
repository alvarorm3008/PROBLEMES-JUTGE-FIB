#include <iostream>

using namespace std;

int main() {
    int a, x;
    while (cin >> a) {
        int res = 0;
        x = a;
        while (a != 0) {
            res += a%10;
            a /= 10;
        }
        cout << "The sum of the digits of " << x << " is " << res << "." << endl;
    }
}
