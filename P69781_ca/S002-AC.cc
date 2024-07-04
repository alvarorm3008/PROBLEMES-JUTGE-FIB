#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX = 100000000;


int main () {
    int x, y, n;
    while (cin >> x >> y >> n) {
        unordered_map <int, int> m;
        int pos = 1;
        bool ciclo = false;
        auto it = m.begin();
        m.insert ({n, 0});
        while (not ciclo and n <= MAX) {
            if (n % 2 == 0) {
                n = n/2 + x;
            }
            else {
                n = 3*n + y;
            }
            it = m.find(n);
            if (it == m.end()) {
                m.insert ({n, pos}); // m[n] = pos;
            }
            else {
                ciclo = true;
            }
            ++pos;
        }
        if (ciclo == true) cout << pos - it->second - 1 << endl; //sino se puede hacer el m.size() - it->second 
        else cout << n << endl;
    }
}
