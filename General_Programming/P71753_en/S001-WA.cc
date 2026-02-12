#include <iostream>
using namespace std;

int main () {
    
    int n;
    int x, max = 0;
    cin >> n;
    
        for (int i = 0; i < n; ++i){
            cin >> x;
            max = x;
            for (int j = 1; j < n; ++j){
                cin >> x;
                if (x > max) max = x;
            }
            cout << max << endl;
        }

}
