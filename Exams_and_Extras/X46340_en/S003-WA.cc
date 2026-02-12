#include <iostream>
#include <cmath>
using namespace std;

int sum_min_max(int x, int y, int z){
	int suma = 0;
	if ((x > y and y > z) or (z > x and x < y)) suma = x + z;
	else if ((x > y and y < z) or (y > x and x < z)) suma = x + y;
	else if ((y > x and x > z) or (z > x and x > y)) suma = y + z;
	return suma;
}


