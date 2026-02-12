#include <iostream>
using namespace std;

int factorial(int n) {
    int suma = 1;
    if (n < 0) suma =0;
    else if (n == 0) suma=1;
    else {
        for (int i = 1; i <= n; ++i) {
            suma = suma*i;
      }
   }
   return suma;
}
/*
int main() {
    int n;
    while (cin >> n) cout << factorial (n) << endl;
}
*/
