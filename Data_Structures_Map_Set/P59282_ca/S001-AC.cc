#include <iostream>
#include <map>
using namespace std;

int main () {
    cout.setf (ios::fixed);
    cout.precision (4);
    string s;
    map<int, int> m; //el segon int es el nombre de vegades que apareix el primer numero al map
    map<int, int>::iterator it;
    int avgd = 0, avgt = 0;
    while (cin >> s) {
        if (s == "number") {
            int n;
            cin >> n;
            it = m.find (n);
            if (it != m.end ()) ++(*it).second; //sumem en nombre de vegades que aquest nombre apareix
            else m.insert (make_pair(n, 1)); //apareix per primera vegada
            ++avgd; //nombres totals + 1
			avgt += n; //la suma dels nombres totals
        }
        else if (m.end () != m.begin()) { //si fem delete i l'estructura no esta buida
            --avgd;
            avgt -= (*m.begin()).first;
            --(*m.begin()).second;
            if (m.begin ()->second == 0) m.erase (m.begin ());
        }
        if (m.size() == 0) cout << "no elements" << endl;
        else cout << "minimum: " << m.begin()->first << ", maximum: " << (--m.end())->first << ", average: " << avgt /double (avgd) << endl;
    }   
}