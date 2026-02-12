#include <iostream>
#include <set>
using namespace std;

int main () {
    string p;
    set <string> s;
    set <string>::iterator it = s.begin(), medio;
    cin >> p;
    if (p != "END") {
        it = s.insert (it, p);
        cout << p << endl;
        medio = s.begin();
        cin >> p;
        while (p != "END") {
            if (p < *medio and s.size() % 2 == 0) --medio;
            else if (p > *medio and s.size() % 2 != 0) ++medio;
            cout << *medio << endl;
            cin >> p; 
        }
    }
}