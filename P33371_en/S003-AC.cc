#include <iostream>
using namespace std;

char encoded(char c, int k) {
    return 'A' + (c - 'a' + k) % 26;
}

int main() {
    int k;
    char c;
    
    while (cin >> k) {
        cin >> c;
        while (c != '.') {
            if (c == '_') cout << ' ';
            else if (c >= 'a' and c <= 'z') cout << encoded (c, k);
            else cout << c;
            cin >> c;
        }
        cout << endl;
    }
}
