#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <int> >Matriu;

Matriu producte(const Matriu& a, const Matriu& b) {
	Matriu Res(a.size(), vector <int>(b[0].size()));
	for (int i = 0; i < Res.size(); ++i) {
		for (int j = 0; j < Res[0].size(); ++j) {
			for (int k = 0; k < a[0].size(); ++k) {
				Res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return Res;
}

int main() {
	int f1, c1, f2, c2;


	cin >> f1 >> c1;
	Matriu Mat1(f1, vector <int>(c1));
	for (int i = 0; i < f1; ++i) {
		for (int j = 0; j < c1; ++j) cin >> Mat1[i][j];
	}
	cin >> f2 >> c2;
	Matriu Mat2(f2, vector <int>(c2));
	for (int i = 0; i < f2; ++i) {
		for (int j = 0; j < c2; ++j) cin >> Mat2[i][j];
	}

	Matriu MatRes = producte(Mat1, Mat2);
	for (int i = 0; i < MatRes.size(); ++i) {
		for (int j = 0; j < MatRes[0].size(); ++j) cout << MatRes[i][j] << ' ';
		cout << endl;
	}
}
