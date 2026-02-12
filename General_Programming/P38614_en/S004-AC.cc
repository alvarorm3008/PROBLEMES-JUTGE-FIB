#include <iostream>
using namespace std;

int main () {
    int n, x;
    cin >> n;
    x = n;
    int suma = 0;
    while (x != 0) {
        suma += x % 10;
        x /= 100;
    }
    if (suma % 2 == 0) cout << n << " IS COOL" << endl;
    else cout << n << " IS NOT COOL" << endl;
}
