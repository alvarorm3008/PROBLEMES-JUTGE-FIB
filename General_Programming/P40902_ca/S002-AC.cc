#include <iostream>
#include <map>
using namespace std;

int main () {
    string nom, op;
    int c;
    map <string, int> m;
    map <string, int>:: iterator it;

    while (cin >> nom >> op) {
        it = m.find (nom);
        if (op == "enters") {
            if (it == m.end ()) m.insert (make_pair (nom, 0));
            else cout << nom << " is already in the casino" << endl;
        }
        else if (op == "wins") {
            cin >> c;
            if (it != m.end ()) (*it).second += c; 
            else cout << nom << " is not in the casino" << endl;
        }
        else {
            if (it != m.end ()) {
                cout << nom << " has won " << (*it).second << endl;
                m.erase (it);
            }
            else cout << nom << " is not in the casino" << endl;
        }
    }
    cout << "----------" << endl;
    it = m.begin ();
    while (it != m.end ()) {
        cout << (*it).first << " is winning " << (*it).second << endl;
        ++it;
    }
}