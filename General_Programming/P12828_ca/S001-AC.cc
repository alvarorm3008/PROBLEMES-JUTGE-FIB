#include <iostream>
#include <vector>

using namespace std;

void escribir (const vector<int>& v, int n) {
    /*
    cout << v[0];
    for (int i = 1; i < n; ++i) cout << ' ' << v[i];
    cout << endl;
    */
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

void zerosuns (int n, vector<int>& sol, int i) {
    if (i == n) escribir (sol, n);
    else {
        sol[i] = 0;
        zerosuns(n, sol, i+1);
        sol[i] = 1;
        zerosuns (n, sol, i+1);
    }
}

int main () {
    int n;
    cin >> n;
    vector<int> sol (n);
    zerosuns(n, sol, 0);
}


//otra manera de hacerlo
/*

void back(vector<int>& sol, int n) {
    if (int(sol.size()) == n) escribir(sol, n);
    else {
        sol.push_back(0);
        back (sol, n);
        sol.pop_back();
        sol.push_back(1);
        back (sol, n);
        sol.pop_back(1);
    }
}

int main () {
    int n;
    cin >> n;
    vector<int> sol;
    zerosuns(n, sol);
}
*/
