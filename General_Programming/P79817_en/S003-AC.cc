#include <iostream>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        int res = 1;
        if (b == 0) res = 1;
        else if (a == 0) res = 0;
        else {
            for (int i = 1; i <= b; ++i) {
            res *= a;
        }
        }
        cout << res << endl;
    }
}
