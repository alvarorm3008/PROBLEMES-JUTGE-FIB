#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

void escribir (const VB& usat1, const VB& usat2, int n, int x, const VI& mon) {
    cout << x << " " << "= ";
    bool p = true;
    for (int i = 0; i < n; ++i) {
        if (usat1[i]) {
            if (p) p = false;
            else cout << " + ";
            cout << mon[i];
        }
        if (usat2[i]) {
            if (p) p = false;
            else cout << " + ";
            cout << mon[i] << 'p';
        }
    }
    cout << endl;
}

void dues_monedes (int x, int n, const VI& mon, VB& usat1, VB& usat2, int i, int suma) {
    if (suma == x) escribir (usat1, usat2, n, x, mon);
    else if (suma < x and i < n) {
        if (not usat1[i]) {
            usat1[i] = true;
            dues_monedes (x, n, mon, usat1, usat2, i, suma + mon[i]);
            usat1[i] = false;
        }
        if (not usat2[i]) {
            usat2[i] = true;
            dues_monedes (x, n, mon, usat1, usat2, i+1, suma + mon[i]);
            usat2[i] = false;
        }
        dues_monedes (x, n, mon, usat1, usat2, i+1, suma);
    }

}

int main () {
    int x, n;
    while (cin >> x >> n) {
        VI mon (n);
        for (int i = 0; i < n; ++i) cin >> mon[i];
        VB usat1 (n, false);
        VB usat2 (n, false);
        sort (mon.begin(), mon.end());

        dues_monedes (x, n, mon, usat1, usat2, 0, 0);
        cout << "---------" << endl;
    }
}