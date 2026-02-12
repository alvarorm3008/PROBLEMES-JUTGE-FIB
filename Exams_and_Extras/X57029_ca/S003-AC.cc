#include <iostream>
#include <vector>
using namespace std;

void bt (int i, int x, int pos, string& sol) {
    if (i == x) cout << sol << endl;
    else {
        if (pos - 1 >= 0) {
            sol[i] = 'd';
            bt (i+1, x, pos-1, sol);
        }
        sol[i] = 'h';
        bt (i+1, x, pos, sol);
        sol[i] = 'u';
        bt (i+1, x, pos+1, sol);
    }
}


int main () {
    int x;
    cin >> x;
    string sol (x, ' ');
    bt (0, x, 0, sol);

}