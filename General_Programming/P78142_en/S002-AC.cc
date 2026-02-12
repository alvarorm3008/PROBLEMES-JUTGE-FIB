#include <iostream>

using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.precision(2);
    double n, i = 0, x = 0;
    
    while (cin>>n){
        i += n;
        ++x;
    
    }
    cout << i / x << endl;
}
