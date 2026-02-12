#include <iostream>
#include <vector>
using namespace std;

void bt (int i, int n, string& sol){
    if (i == n) cout << sol << endl;
    else {
        sol[i] = 'A';
        bt (i+1, n, sol);
        sol[i] = 'B';
        bt (i+1, n, sol);
        sol[i] = 'C';
        bt (i+1, n, sol);
        sol[i] = 'G';
        bt (i+1, n, sol);
        sol[i] = 'T';
        bt (i+1, n, sol);
    }
}

int main () {
    int n;
    cin >> n;
    string sol (n, ' ');
    bt (0, n, sol);
}