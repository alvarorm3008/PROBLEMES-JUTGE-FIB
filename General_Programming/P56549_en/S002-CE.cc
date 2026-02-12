#include <iostream>
using namespace std;

void base2(int x) {
    if (x < 2) cout << x;
            else {
                base2(x/2);
                cout << x%2;
            }
}

void base8(int x) {
    if (x < 8) cout << x;
    else {
        base8(x/8);
        cout << x%8;
    }
}

void base16(int x) {
    if (x < 16) {
        if (x == 15) cout << 'F';
        else if (x == 14) cout << 'E';
            else if (x == 13) cout << 'D';
                else if (x == 12) cout << 'C';
                    else if (x == 11) cout << 'B';
                        else if (x == 10) cout << 'A';
                        else cout << x;
    }
    else {
        base16(x/16);
        if (x%16 == 15) cout << 'F';
            else if (x%16 == 14) cout << 'E';
                else if (x%16 == 13) cout << 'D';
                    else if (x%16 == 12) cout << 'C';
                        else if (x%16 == 11) cout << 'B';
                            else if (x%16 == 10) cout << 'A';
                                else cout << x%16;
    }
}

int main() {
    int x;
    while (cin >> x) {
        cout << x << " = ";
        base2(x);
        cout << ", ";
        base8(x);
        cout << ", ";
        base16(x);
        cout << endl;
    }
}
Certificate
