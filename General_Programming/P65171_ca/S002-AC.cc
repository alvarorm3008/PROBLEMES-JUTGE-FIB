#include <iostream>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(2);
    double n, suma1 = 0, suma2 = 0, suma3 = 0, suma = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        double x;
        cin >> x;
        suma = x * x;
        suma1 += suma;
        suma2 += x;
        suma3 = suma2 * suma2;
    }
    cout << (1/(n - 1)) * (suma1) - (1 / (n*(n - 1))) * suma3 << endl;
}
