#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <int> >Matriu;

Matriu producte(const Matriu& a, const Matriu& b) {
	int k = a.size();
	Matriu c(k, vector <int>(k, 0));
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			for (int l = 0; l < k; ++l) c[i][j] += a[i][l] * b[l][j];
		}
	}
	return c;
}
