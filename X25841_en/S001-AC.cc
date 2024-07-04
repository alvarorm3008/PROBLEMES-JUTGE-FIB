#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, res = 0;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        res += v[i];
    }
    cout << res << endl;
}
