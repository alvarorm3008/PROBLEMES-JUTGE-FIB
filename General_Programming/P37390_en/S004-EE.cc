#include <vector>
#include <iostream>
using namespace std;

typedef vector< vector<int> > Matrix;

Matrix product(const Matrix& a, const Matrix& b) {
	int h = a.size();
	Matrix c(h, vector<int>(h,0));
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < h; ++j){
			for (int l = 0; l < h; ++h) c[i][j] += a[i][l] * b[l][j];
		}
	}	
	return c;
}

int main ()
{
    int n;
    while (cin >> n) {
        Matrix a(n, vector<int>(n));
        Matrix b(n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> a[i][j];
        }   }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> b[i][j];
        }   }
        Matrix c = product(a,b);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }   
        cout << endl;
    }
}
