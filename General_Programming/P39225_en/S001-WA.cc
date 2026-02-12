#include <iostream>
using namespace std;

int main (){
    
    int n, x, count = 0;
    bool found = false;
    cin >> x;
    
    while (cin >> n and not found){
        ++count;
       if (n == x) found = true;
    }
    cout << "At the position " << x << " there is a(n) " << n << " ."<< endl;
}
