#include <iostream>
void decompose(int n, int& h, int& m, int& s) {
    m = n / 60;
    s = n % 60;
    h = m / 60;
    m = m % 60;
}
