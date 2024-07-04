#include <iostream>
using namespace std;

int main (){
    
    int n, x, count = 1, k;
    bool found = false;
    cin >> x;
    
    while (cin >> n and not found){
        ++count;
        if (x == count) found = true;
        k = x;
    }
    if (found) cout << "At the position " << k << " there is a(n) " << n << "."<< endl;
    else cout << "Incorrect position." << endl;

}
