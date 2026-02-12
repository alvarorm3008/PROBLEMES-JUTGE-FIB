#include <iostream>

using namespace std;

int main(){
    
    int n, remind = 0, reversed = 0;
    cin >> n;
    
    while (n != 0){
     remind = n % 10;      
     reversed = reversed * 10 + remind;    
     n /= 10;
    }
    if (n==0) cout << n << endl;
    else cout << reversed << endl;
    
    return 0;
}
