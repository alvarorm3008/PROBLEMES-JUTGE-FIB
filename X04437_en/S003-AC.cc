#include <iostream>
#include <cmath>
using namespace std;

double dist_or(double x, double y){
	double hipotenusa = sqrt((x * x + y * y));
	return hipotenusa;
}

int main() {
	int a, b;
	while (cin >> a >> b) cout << dist_or(a, b);
}

