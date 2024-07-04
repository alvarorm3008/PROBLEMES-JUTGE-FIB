#include <iostream>
#include <vector>
using namespace std;

int posicio_maxim(const vector<double>& v, int m) {
	int tam = v.size();
	for (int i = 1; i < tam; ++i) {
		int j = i;
		double x = v[j];
		while (j > 0 && x < v[j - 1]) {
			v[j] = v[j - 1];
			--j;
		}
		v[j] = x;
	}
}
