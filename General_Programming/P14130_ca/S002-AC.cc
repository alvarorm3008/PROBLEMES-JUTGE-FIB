#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }
    int cont=0;
    for (int i=0; i< n-1; ++i) {
        if (v[i]==v[n-1]) ++cont;
    }
    cout << cont << endl;
}