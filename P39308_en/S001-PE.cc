#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    int n, divisor;
    
    while (cin >> n){
        cout << "divisors of " << n << ": ";
        divisor = 1;
        int aux = sqrt(n);
        while (divisor <= aux){ //divisores peques
            if (n % divisor == 0) cout << ' ' << divisor;
            ++divisor;
        }
        while (aux > 0){ //divisores grandes
            if (n % aux == 0 and aux != n / aux) cout << ' ' << n/aux;
            --aux;
        }
        cout << endl;
    }
}
