#include <iostream>
#include <map>
using namespace std;

int main () {
    string op;
    map <string, int> m;
    map <string, int>::iterator it;
    while (cin >> op) {
        if (op == "minimum?") {
            if (m.empty()) cout << "indefinited minimum" << endl;
            else {
                it = m.begin();
                cout << "minimum" << (*it).first << ", " << (*it).second << "time(s)" << endl;
            }
         }
        else if (op == "maximum?") {
            if (m.empty()) cout << "indefinited maximum" << endl;
            else {
                it = --m.end();
                cout << "maximum" << (*it).first << ", " << (*it).second << "time(s)" << endl;
            }  
        }
        else if (op == "store") {
            cin >> op;
            it = m.find (op);
            if (it != m.end ()) ++(*it).second;
            else m.insert (make_pair (op, 1));
        }
        else {
            cin >> op;
            it = m.find (op);
            if (it != m.end ()) {
                --(*it).second;
                if ((*it).second == 0) m.erase (it);
            }
        }
    }
}