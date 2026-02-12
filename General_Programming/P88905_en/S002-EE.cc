#include <vector>
#include <iostream>
using namespace std;

typedef vector< vector<int> > Matrix;

Matrix product(const Matrix& a, const Matrix& b) {
	int h = a.size();
	Matrix c(h, vector<int>(h,0));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < h; ++j)
			for (int l = 0; l < h; ++h) c[i][j] += a[i][l] * b[l][j];
	return c	;
}


