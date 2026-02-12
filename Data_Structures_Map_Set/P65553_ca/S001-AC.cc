#include <iostream>
#include <map>
using namespace std;

map<string, int>::iterator it;

int main () {
    int n;
    while (cin >> n) {
        map<string, int> m;
        int total = 0;
        for (int i = 0; i < n; ++i) {
            string ini;
            cin >> ini;  
            it = m.find(ini); 
            if (m.find(ini) != m.end()) {
                ++it->second;
            }
            else m.insert({ini, 1});
            ++total;
        }
        int j;
        cin >> j;
        for (int i = 0; i < j; ++i) {
            string nou;
            cin >> nou;
            it = m.find(nou);
            if (it != m.end()) {
                if (it->second + 1 <= total - it->second) {
                    ++it->second;
                    ++total;
                }
            }
            else {
                m.insert({nou, 1});
                ++total;
            }
        }
        for (it = m.begin(); it != m.end(); ++it) {
            cout << it->first << ' ' << it->second << endl;
        }
        cout << string (20, '-') << endl;
    }
}
