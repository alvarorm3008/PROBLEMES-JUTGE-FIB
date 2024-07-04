#include <iostream>
using namespace std;

int main () {
    int n, x, count = 0;
    cin >> n;
    cin >> x;
    while (cin >> x) {
        if (n % x == 0) ++count;
    }
    cout << count << endl;
}
