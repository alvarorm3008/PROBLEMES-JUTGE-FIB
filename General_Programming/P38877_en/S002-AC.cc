#include <iostream>
using namespace std;

void girant_paraules(int& n) {
    string x;
    if (cin >> x){
        girant_paraules(n);
        if (n > 0) cout << x << endl;
        --n;
    }
}

int main() {
    int n;
    cin >> n;
    girant_paraules(n);
}