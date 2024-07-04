#include <iostream>
using namespace std;

int sum_min_max(int x, int y, int z){
	int max = 0, min = 0, suma = 0;
	if (x > y and x > z){
		if (y < z) min = y;
		else min = z;
		max = x;
	}
	else if (y > x and y > z){
		if (x < z) min = x;
		else min = z;
		max = y;
	}
	else if (z > x and z > y){
		if (y < x) min = y;
		else min = x;
		max = z;
	}
	suma = max + min;
	
	return suma;
}
			
int main() {
	int a, b, c;
	while (cin >> a >> b >> c) cout << sum_min_max (a, b, c) << endl;
}
