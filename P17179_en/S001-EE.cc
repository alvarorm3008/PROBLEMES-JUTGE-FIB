#include <iostream>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);
    
    int n, n1;
    double x, promedio = 0, max = 0, min = 0, c = 1;
    cin >> n;
    
        for (int i = 0; i < n; ++i){
            c = 1;
            cin >> n1;
            cin >> x;
            max = min = promedio = x;
            for (int j = 0; j < n1; ++j){
                cin >> x;
                if (x > max) max = x;
                if (x < min) min = x;
                promedio += x;
                ++c;
            }
            cout << min << " " << max << " " << promedio / c << endl;
        }
}
