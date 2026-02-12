#include <iostream>
#include <cmath>
using namespace std;

int sum_min_max(int x, int y, int z){
	int suma;
	if (x > y and y > z) suma = x + z;
	else if (x > y and y < z) suma = x + y;
	else if (x < y and x < z) suma = y + z;
	return suma;
}
