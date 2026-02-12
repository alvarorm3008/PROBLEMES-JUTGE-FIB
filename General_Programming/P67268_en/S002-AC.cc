#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
        if (n != 0) {
        vector<int> v(n);
        for (int i = 0; i < v.size(); ++i) {
            cin >> v[i];
        }
        cout << v[v.size()-1];
        for (int i = v.size()-2; i >= 0; --i) {
            cout << ' ' << v[i];

        }
        }
        cout << endl;
    }
}