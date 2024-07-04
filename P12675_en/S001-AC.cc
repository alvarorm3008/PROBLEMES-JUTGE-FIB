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

