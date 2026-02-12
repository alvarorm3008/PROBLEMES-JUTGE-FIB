#include <iostream>
bool is_valid_date(int d, int m, int a) {
	bool isleap, fail;
	fail = false;

	if ((a % 4 == 0 and a % 100 != 0) or (a % 100 == 0 and (a / 100 % 4) == 0)) isleap = true;
	else isleap = false;

	if (a < 1800 or a > 9999) fail = true;
	if (m <= 0 or m > 12) fail = true;

	if ((m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12) and (0 < d and d <= 31)) fail = false;
	else if (m == 2) {
		if (isleap and (d <= 0 or d > 29)) fail = true;
		if (not isleap and (d <= 0 or d > 28)) fail = true;
	} else if (d <= 0 or d > 30) fail = true;
	return not fail;
}
