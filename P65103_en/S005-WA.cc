#include <iostream>
using namespace std;

int main (){
    
    int n, x, count = 1;
    bool found = false;
    cin >> x;
    
    while (cin >> n and not found){
        ++count;
        if (x == count) found = true;
    }
    if (found) cout << "At the position " << x << " there is a(n) " << n << "."<< endl;
    else cout << "Incorrect position." << endl;

}
