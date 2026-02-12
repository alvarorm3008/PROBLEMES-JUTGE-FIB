#include <iostream>
#include <vector>
using namespace std;

int common_elements(const vector <int>& X, const vector <int>& Y) {
	int commons = 0;
	int x = X.size();
	int y = Y.size();
	int i = 0;
	int j = 0;
	while (i <= x-1 && j <= y-1) {
		if (X[i] == Y[j]) {
			++commons;
			++i;
			++j;
		} else if (X[i] > Y[j])   {
			++j;
		} else if (X[i] < Y[j])   {
			++i;
		}
	}

	return commons;
}

int main ()
{
    int n, m;
    while (cin >> m >> n) {

        vector<int> X(m);
        for (int i=0; i<m; ++i) cin >> X[i];

        vector<int> Y(n);
        for (int i=0; i<n; ++i) cin >> Y[i];

        cout << common_elements(X,Y) << endl;

    }
    return 0;
}