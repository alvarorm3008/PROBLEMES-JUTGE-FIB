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
   cout << reversed << endl;
    
    return 0;
}
