#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res += x;
    }
    cout << res << endl;
}
