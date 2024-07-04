#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main () {
    string s;
    while (getline (cin, s)) {
        istringstream ss(s);
        set <int> seq;
        int x;
        while (ss >> x) seq.insert(x);
        
        if (seq.empty()) cout << 0 << endl;
        else {
            int cont = 1;
            auto ant = seq.begin();
            auto act = ant; ++act;
            while (act != seq.end()) {
                if (*act%2 != *ant%2) ++cont; //if (*ant+*act%2 != 0)
                ++ant;
                ++act;
            }
            cout << cont << endl;
        }
    }
}