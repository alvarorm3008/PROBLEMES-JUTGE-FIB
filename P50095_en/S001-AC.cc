#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) return false;
    }
    return true;
}


int main() {
    
    int n;
    cin >> n;
    
    while (is_prime(n)) {
        ++n;
        while (not is_prime(n)) ++n;
        cout << n << endl;
        cin >> n;
    }
}
