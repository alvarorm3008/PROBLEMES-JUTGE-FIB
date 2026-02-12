#include <iostream>
using namespace std;


//Funcio que llegeix una fraccio de num/den i la simplifica (fent mcd)
//Pre: entren num i den
//Post: els valors simplificats

void read_rational(int& num, int& den) {
	char c;
	cin >> num >> c >> den;
	int r, cnum = num, cden = den;
	while (cden != 0) {
		r = cnum % cden;
		cnum = cden;
		cden = r;
	}
	num /= cnum;
	den /= cnum;
}
