#include <iostream>

using namespace std;

int main(){
    
    int n, remind = 0;
    cin >> n;
    if (n == 0) cout << n << endl;
    else {
    while (n != 0){
     remind = n % 16;      
     n /= 16;
     cout << remind;
    }
    cout << endl;
    }
   
    
    return 0;
}
