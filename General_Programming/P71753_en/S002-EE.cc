#include <iostream>
using namespace std;

int main() {
    
    int num, n, max;
    while (cin >> num){
        cin >> max;
        for (int i = 1; i < n; ++i){
            cin >> n;
            if (n > max) max = n;
        }
    cout << max << endl;
    }
}
