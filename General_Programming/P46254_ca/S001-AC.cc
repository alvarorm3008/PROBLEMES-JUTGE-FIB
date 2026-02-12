#include <iostream>
#include <cmath>
using namespace std;

struct Punt {
	double x, y;
};

void llegeix(Punt& n) {
	cin >> n.x >> n.y;
}

double distancia(const Punt& a, const Punt& b) {
	return sqrt((b.x-a.x) * (b.x-a.x)+(b.y-a.y) * (b.y-a.y));
}


