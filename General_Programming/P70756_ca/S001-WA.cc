#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, p;
vector<string> par;
vector<int> sol;

void escribir () {
    for (int i = 0; i < p; ++i) {
        cout << "subconjunt " << i+1 << ": " << '{';
        bool primer = true;
        for (int j = 0; j < n; ++j) {
            if (sol[j] == i) {
                if (primer) primer = false;
                else cout << ',';
                cout << ',' << par[j];
            }
        }
        cout << '}' << endl;
    }
    cout << endl;
}

void particions (int i) {
    if (i == n) escribir();
    else {
        for (int j = 0; j < p; ++j) {
            sol[i] = j;
            particions (i+1);
        }
    }
}

int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        par.push_back(s);
    }
    cin >> p;
    sol = vector<int> (n);
    particions (0);
}