#include <iostream>

using namespace std;

int main(){
    
    int n, remind = 0;
    cin >> n;
    if (n == 0) cout << n << endl;
    else {
    while (n != 0){
     remind = n % 10;      
     n /= 10;
     cout << remind;
    }
    cout << endl;
    }
   
    
    return 0;
}
