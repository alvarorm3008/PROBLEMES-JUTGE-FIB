#include <iostream>
using namespace std;

int sum_of_digits(int x) {
    if (x == 0) return(0);
	else return ((x % 10) + sum_of_digits(x/10));
}
int main() {
    int x;
    while (cin >> x) {
        if (sum_of_digits(x) > 10) cout << sum_of_digits(x) / 10 << endl;
        else cout << sum_of_digits(x) << endl;
    }
}

