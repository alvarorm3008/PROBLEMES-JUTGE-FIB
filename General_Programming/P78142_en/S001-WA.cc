#include <iostream>

using namespace std;

int main(){

    double n, i = 1, x = 1;
    cin >> n;
    cout.setf(ios::fixed);
    cout.precision(2);
    while (cin>>n){
        i += n;
        ++x;
    }
    cout << i / x << endl;
}
