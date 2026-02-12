#include <iostream>
#include <set>
using namespace std;

struct compare {
    bool operator()(const string&a, const string&b) {
        if (a.length() == b.length()) return a < b;
        return a < b;
    }
};

int main () {
    set <string> has;
    set <string, compare> had;
    string input;
    int partida = 1;
    bool quit = 0, first = true;

    cin >> input;
    while (not quit) {
        while (not (input == "END" or input == "QUIT")) {
            if (has.count(input)) {
                has.erase (input);
                had.insert (input);
            }
            else {
                has.insert (input);
                has.erase (input);
            }
            cin >> input;
        }
        if (not first) cout << endl;
        first = false;

        cout << "GAME#" << partida << endl << "HAS:" << endl;
        for (string elem : has) cout << elem << endl;
        cout << endl << "HAD:" << endl;
        for (string elem : had) cout << elem << endl;

        ++partida;
        has.erase (has.begin(), has.end());
        had.erase (has.begin(), has.end());

        if (input == "QUIT") quit = 1;
        else cin >> input;
    }
}