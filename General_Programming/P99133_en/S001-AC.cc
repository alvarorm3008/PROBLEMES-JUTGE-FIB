#include <iostream>
#include <string>
using namespace std;

void Reversing_words(int& n) {
    if (n > 0) {
        string x;
        cin >> x;
        Reversing_words(--n);
        for (int i = x.length() - 1; i >= 0; --i) {
            cout << x[i];
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    Reversing_words(n);
}
