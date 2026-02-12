#include <iostream>
using namespace std;

int main () {
    
    int x, n, ultims_x, ultims_n, count = 0;
    cin >> x;
    ultims_x = x % 1000;
    cout << "nombres que acaben igual que " << x << ":" << endl;
    while (cin >> n) {
            ultims_n = n % 1000;
            if (ultims_x == ultims_n) {
                ++count;
                cout << n << endl;
    }
    }
    cout << "total: " << count << endl;
}
