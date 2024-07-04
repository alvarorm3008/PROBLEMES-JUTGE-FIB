#include <iostream>

using namespace std;

int main() {
    int base, n;
    while (cin >> base >> n) {
        int cont = 0;
        while (n != 0) {
            n /= base;
            ++cont;
        }
        cout << cont << endl;
        
    }
}
