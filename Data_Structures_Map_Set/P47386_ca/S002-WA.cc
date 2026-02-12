#include <iostream>
#include <map>
#include <set>

using namespace std;

int main () {
    string s, x, y;
    map<string, string> m;
    set<string> solters;
    while (cin >> s) {
        if (s == "liats") {
            cin >> x >> y;
            solters.erase(x);
            solters.erase(y);
            solters.insert(m[x]);
            solters.insert(m[y]);
            m.erase (m[x]);
            m.erase (m[y]);
            m[x] = y;
            m[y] = x;   
        }
        else {
            cout << "PARELLES:" << endl;
            for (auto parelles : m) {
                cout << parelles.first << ' ' << parelles.second << endl;
                m.erase (parelles.second);
            }
            cout << "SOLS:" << endl;
            if (not solters.empty()) {
                for (string sol : solters) {
                    cout << sol << endl;
                }
            }
            cout << string(10, '-') << endl;
        }
    }
}

