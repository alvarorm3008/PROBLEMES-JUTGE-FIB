#include <iostream>
#include <vector>
using namespace std;

int first_ocurrence_rec (double x, const vector<double>& v, int a, int b) {
    if (a > b) return -1;
    int pos = (a + b) / 2;
    if (x < v[pos]) return first_ocurrence_rec (x, v, a, pos-1);
    else if (x > v[pos]) return first_ocurrence_rec (x, v, pos+1, b);
}

int first_occurrence(double x, const vector<double>& v) {
    if (v.empty() or x < v[0] or v[v.size() - 1] < x) return -1;
    else return first_ocurrence_rec(x, v, 0, v.size() - 1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}