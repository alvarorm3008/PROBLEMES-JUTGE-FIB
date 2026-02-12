#include <iostream>
using namespace std;

int sum_min_max(int x, int y, int z) {
	int max, min;
	if (x < y and x < z) {
		min = x;
		if (y > z) max = y;
		else max = z;
	} else if (y < x and y < z) {
		min = y;
		if (x > z) max = x;
		else max = z;
	} else {
		min = z;
		if (x > y) max = x;
		else max = y;
	}
	return max+min;
}
