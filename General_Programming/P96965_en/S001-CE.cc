#include <iostream>
using namespace std;

int sum_digits (int n) {
    if (n < 10) return n;
    return n % 10 + sum_digits (n / 10);
}

/*bool is_perfect(int n) {
    return is_perfect(sum_digits(n));
}
*/
int main() {
    int n ;
    while (cin >> n) cout << sum_digits(n) << endl;
}

    
