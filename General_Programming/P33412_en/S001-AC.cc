#include<iostream>
#include<vector>
using namespace std;

bool resis_rec(double x, const vector<double>& v, int e, int d) {
	if (e > d) return false;
	int m = (e + d)/2;
	if (v[m] == x) return true;
	else if (v[m] > x) {
		if (m < d and v[m+1] == x) return true;
		return resis_rec(x, v, e, m-1);
	}
	else { //v[m] < x
		if (m > e and v[m-1] == x) return true;
		return resis_rec(x, v, m+1, d);
	}
}

bool resistant_search(double x, const vector<double>& v) {
	return resis_rec(x, v, 0, v.size()-1);
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
            cout << resistant_search(x, V) << endl;
        }
    }
}


