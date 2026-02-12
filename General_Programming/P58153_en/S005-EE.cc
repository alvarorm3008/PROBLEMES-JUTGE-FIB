#include <iostream>
using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.precision(10);
    int a, b;
    double h_1 = 0.0, h_2 = 0.0;
    cin >> a >> b;
    for (int i = 1; i <= a; ++i) {
        h_1 += 1.0/i;
    }
    for (int i = 1; i <= b; ++i) {
        h_2 += 1.0/i;
    }
    cout << h_1 - h_2 << endl;
}
