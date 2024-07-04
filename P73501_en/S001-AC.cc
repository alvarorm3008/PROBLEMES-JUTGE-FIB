#include <iostream>
using namespace std;

int main () {
    
    int x, n, a= 0, count = 0;
    bool first = true;
    cin >> x;
    
    while (cin >> n){
        if (n != 0) {
            if (not first and n > a) ++count;
            a = n;
            first = false;
        }
        else {
            cout << count << endl;
            count = 0;
            first = true;
        }
    }
}
