#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Matriu;

int main () {
	int m, fin, ini;
	cin >> m >> fin >> ini;
	
	Matriu mat(m, vector<char>(100, '.'));
	for (int i = 0; i < m; ++i) {
		if (i == fin) mat[i][0] = '=';
		else mat[i][0] = '|';
	}
	mat[ini][1] = 'V';
	int mov = 1;
	bool abajo = true;
	int i = ini;
	int j = 1;
	
	while (i != fin) {
		int cont_mov = 0;
		while (cont_mov < mov and i != fin) {
			++j;
			if (abajo) ++i;
			else --i;
			mat[i][j] = 'V';
			++cont_mov;
		}
		mov *= 2;
		if (abajo) abajo = false;
		else abajo = true;
	}
	for (int k = 0; k < m; ++k) {
		for (int l = 0; l <= j; ++l)
			cout << mat[k][l];
		cout << endl;
	}
}
