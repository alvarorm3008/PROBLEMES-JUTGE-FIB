#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int evaluate(const vector <int>& p, int x) {
	int n = p.size(), aux, sum = 0;
	for (int i = 0; i < n; ++i) {
		aux = pow(x, i);
		sum += (p[i] * aux);
	}
	return sum;
}