#include <iostream>
using namespace std;

int main (){
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        cout << a ;
        
        bool prime = true;
        int j = 2;
        while (prime and j * j <= a) {
            if (a % j == 0) prime = false;
            ++j;
        }
        if (a > 1 and prime) cout << " is prime";
        else cout << " is not prime";
        cout << endl;
    }
}
