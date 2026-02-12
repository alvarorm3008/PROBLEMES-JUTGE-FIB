#include <iostream>
using namespace std;

bool is_leap_year(int year){
	bool is = false;
	if ((year != 1800) && (year != 1900) && (year != 2000)){
		if ((year % 4 == 0 && year % 100) || (year % 100 == 0) && (year /100 % 4 == 0)) is = true;
	}
	else if (year == 2000) is = true ;
	return is;
} 

int main() {
	int year;
	while (cin >> year) cout << (is_leap_year (year) ? "true" : "false") << endl;
}

