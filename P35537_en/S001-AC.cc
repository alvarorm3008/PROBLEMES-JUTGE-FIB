#include <iostream>
using namespace std;

bool is_increasing(int n) {
    if (n < 10) return true;
    return ((n / 10) % 10 <= (n % 10) and is_increasing (n / 10));
}

int main() {
    int n;
    while (cin >> n) cout << (is_increasing (n) ? "true" : "false") << endl;
}
