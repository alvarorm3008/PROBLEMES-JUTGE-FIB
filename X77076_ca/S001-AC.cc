#include <iostream>
#include <vector>
using namespace std;

int first_rec(double x, const vector<double>& v, int i, int j) {
	if (i > j) return -1;
	int m = (i+j)/2;
	if (v[m] < x) {
		if (m > i and v[m-1] == x) return m-1;
		else return first_rec(x, v, m+1, j);
	}
	else {
		int p = first_rec(x, v, i, m-1);
		if (p == -1) {
			if (v[m] == x) return m;
			else if (m < j and v[m+1] == x) return m+1;
		}
		return p;
	}
}

int first_occurrence(double x, const vector<double>& v) {
	return first_rec(x, v, 0, v.size()-1);
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