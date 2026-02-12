#include <iostream>
using namespace std;

void girant_paraules(int& n, int& count) {
    string x;
    if (cin >> x) {
        ++n;
        ++count;
        girant_paraules(n,count);
        --n;
        if (count > (n / 2)) cout << x << endl;
    }
}

int main() {
    int n = 0;
    int count = 0;
    cin >> n;
    girant_paraules(n,count);
}
