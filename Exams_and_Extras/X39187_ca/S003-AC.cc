#include <iostream>
#include <vector>
using namespace std;

void bt (int i, int n, int c, int accions, string& sol) {
    if (i == n) cout << sol << endl;
    else {
        if (c > 0) {
            sol[i] = 'b';
            bt (i+1, n, c-1, accions+1, sol);
        }
        if (accions > 0) {
            sol[i] = 's';
            bt (i+1, n, c+1, accions-1, sol);
        }
    }
}


int main () {
    int n, c;
    cin >> n >> c;
    string sol (n, ' ');
    bt (0, n, c, 0, sol);

}