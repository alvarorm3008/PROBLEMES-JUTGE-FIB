#include <iostream>
using namespace std;

int sum_digits (int n) {
    if (n < 10) return n;
    return n % 10 + sum_digits (n/10);
}
// pensar recursiva para numeros primos
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) return false;
    }
    return true;
}

bool is_perfect_prime(int n) {
    if (not is_prime(n)) return false;
    if (n < 10 and is_prime(n)) return true;
    return is_perfect_prime(sum_digits(n));
}

int main() {
    int n;
    while (cin >> n) cout << (is_perfect_prime(n) ? "true" : "false") << endl;
}