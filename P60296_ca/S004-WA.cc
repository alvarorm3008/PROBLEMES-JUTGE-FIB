#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Compare {
    bool operator () (const pair <string, int> &a, const pair <string, int> &b) const {
        if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
    }
};

int main () {
    map<string, pair<int, bool>> m;
    map<string, pair<int, bool>>::iterator it;
    int elo_inici = 1200;
    string op, nom1, nom2;
    while (cin >> op >> nom1) {
        it = m.find(nom1);
        if (op == "LOGIN") {
            if (it == m.end()) {
                m.insert ({nom1, make_pair(elo_inici, true)});
            }
        }
        else if (op == "LOGOUT") {
            if (it != m.end()) {
                (*it).second.second = false;
            }
        }
        else if (op == "PLAY") {
            cin >> nom2;
            auto it1 = m.find(nom2);
            if (not (*it).second.second) cout << "jugador(s) no connectat(s)" << endl;
            else if (not (*it1).second.second) cout << "jugador(s) no connectat(s)" << endl;
            else {
                (*it).second.first += 10;
                if ((*it1).second.first - 10 >= 1200) (*it1).second.first -= 10;
            }
        }
        else {
            cout << nom1 << " " << (*it).second.first << endl;
        }
    }
    cout << endl << "RANKING" << endl;

    set <pair <string, int>, Compare> aux;
    set <string, int>::iterator it1;
    for (it = m.begin(); it != m.end(); ++it) aux.insert ({it->first, (*it).second.first});
    for (pair <string, int>its : aux) cout << its.first << ' ' << its.second << endl;

}