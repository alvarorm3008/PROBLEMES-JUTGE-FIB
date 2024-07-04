#include <iostream>
using namespace std;

int Prefixed_expression() {
    char c;
    cin >> c;
    if (c >= '0' and c <= '9') return c - '0';
    else {
        int x = Prefixed_expression();
        int y = Prefixed_expression();
        if (c == '+') return x + y;
        else if (c == '*') return x * y;
        else return x - y;
    }
}

int main() {
    cout << Prefixed_expression() << endl;
}