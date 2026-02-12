#include <iostream>
#include <map>

using namespace std;

int main () {
    string s, x, y;
    map<string, string> m;
    while (cin >> s) {
        if (s == "liats") {
            cin >> x >> y;
            auto it = m.find(x);
            if (it != m.end()) { //esta
                if (it->second != "") {
                    auto it1 = m.find(it->second);
                    it1->second = "";
                }
                it->second = y;
            }
            else m.insert ({x, y});

            it = m.find(y);
            if (it != m.end()) { //esta
                if (it->second != "") {
                    auto it1 = m.find(it->second);
                    it1->second = "";
                }
                it->second = x;
            }
            else m.insert ({x, y});
        }
        else {
            cout << "PARELLES:" << endl;
            for (auto it = m.begin(); it != m.end(); ++it) 
                if (it->second != "" and it->first < it->second) cout << it->first << " " << it->second << endl;
                
            cout << "PARELLES:" << endl;
            for (auto it = m.begin(); it != m.end(); ++it) 
                if (it->second == "") cout << it->first << endl;

            cout << string (10, '-') << endl;
       }
    }
}

