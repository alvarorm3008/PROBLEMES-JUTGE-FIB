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
    if (found) cout << "At the position " << n << " there is a(n) " << k << "."<< endl;
    else cout << "Incorrect position." << endl;

}
