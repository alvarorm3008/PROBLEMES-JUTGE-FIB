#include <iostream>
using namespace std;

int main (){
    
    int n, x, count = 0;
    bool found = false;
    cin >> x;
    
    while (not found){
        cin >> n;
        ++count;
       if (x == count) found = true;
    }
    cout << "At the position " << x << " there is a(n) " << n << "."<< endl;
}
