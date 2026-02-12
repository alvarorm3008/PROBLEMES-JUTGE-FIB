#include <iostream>

using namespace std;

int main (){
    int f, c, res = 0;
    char coins;
    cin >> f >> c;
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            
            cin >> coins;
            if ((i + j)%2 == 0) res += coins -'0';
        }
    }
    cout << res << endl;
}
