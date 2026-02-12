#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
	if (esq > dre) return -1;
	int mitj = (esq + dre) / 2;
	if (x < v[mitj]) return posicio (x, v, esq, mitj - 1);
	if (x > v[mitj]) return posicio (x, v, mitj + 1, dre);
	return mitj;
	
}
