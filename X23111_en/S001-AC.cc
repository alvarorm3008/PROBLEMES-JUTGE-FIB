#include <iostream>
using namespace std;

int main () {
    string s, t;
    while (cin >> s >> t) {
        if (s < t) cout << s << " " << t << endl;
        else cout << t << " " << s << endl;
    }
}
