#include <vector>
#include <iostream>
using namespace std;

typedef vector< vector<int> > Matrix;

Matrix product(const Matrix& A, const Matrix& B) {
	int h = A.size();
	Matrix res(h, vector<int>(h,0));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < h; ++j)
			for (int l = 0; l < h; ++h) res[i][j] += A[i][l] * B[l][j];
	return res;
}

int main ()
{
    int n;
    while (cin >> n) {
        Matrix A(n, vector<int>(n));
        Matrix B(n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> A[i][j];
        }   }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> B[i][j];
        }   }
        Matrix C = product(A,B);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }   
        cout << endl;
    }
}
