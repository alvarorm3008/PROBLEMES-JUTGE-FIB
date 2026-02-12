#include <iostream>
#include <vector>
using namespace std;

bool usat (vector<char>&usats, char c) {
    for (int i = 0; i < usats.size(); ++i) {
        if (usats[i] == c) return true;
    }
    return false;
}

void bt (int i, int n, string& sol, vector<char>& usats) {
    if (i == n) cout << sol << endl;
    else {
        for (int j = 0; j < n; ++j) {
            char c = j + 'a';
            if (i == 0 or (not usat(usats, c) and c - 1 != sol[i-1])) {
                usats.push_back(c);
                sol[i] = c;
                bt (i+1, n, sol, usats);
                usats.pop_back();
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    string sol (n, ' ');
    vector<char> usats;
    bt (0, n, sol, usats);
}