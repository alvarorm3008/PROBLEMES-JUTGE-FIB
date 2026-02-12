#include <iostream>
#include <cmath>
using namespace std;

int interest (double m, double f, double per, int min, int max) {
    if (min <= max) {
        int mid = (min+max) / 2;
        double bank = pow(per, mid)*m;
        double prof = mid*f + m;

        if (prof < bank) return interest (m, f, per, min, mid - 1);
        else if (prof > bank) return interest (m, f, per, mid + 1, max);
        return mid;
    }
    return min;
}

int main () {
    double m, f, r;
    while (cin >> m >> f >> r) {
        double per = r/100 + 1;
        cout << interest (m, f, per, 1, 10000000) << endl; 
    }
}