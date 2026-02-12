#include <iostream>

using namespace std;

int main() {
    int a;
    while (cin >> a) {
        int res = 0;
        while (a != 0) {
            res += a%10;
            a /= 10;
        }
        cout << res << endl;
    }
}
