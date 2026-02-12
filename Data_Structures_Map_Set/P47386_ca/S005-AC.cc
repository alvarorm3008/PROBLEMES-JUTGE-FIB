#include <iostream>
#include <map>
#include <set>

using namespace std;

int main () {
    string s, x, y;
    map<string, string> m;
    while (cin >> s) {
        if (s == "liats") {
            cin >> x >> y;
            if (m[x] != "") m[m[x]] = "";
            if (m[y] != "") m[m[y]] = "";
            m[x] = y;
            m[y] = x;
              
        }
        else {
            cout << "PARELLES:" << endl;
            for (auto parelles : m) {
                if (parelles.second != "" and parelles.first < parelles.second) cout << parelles.first << ' ' << parelles.second << endl;
            }
            cout << "SOLS:" << endl;
            for (auto solters : m) {
                if (solters.second == "") cout << solters.first << endl;
            }
            cout << string (10, '-') << endl;
        } 
    }
}

