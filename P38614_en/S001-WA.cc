#include <iostream>

using namespace std;

int main (){
    
    int n, reminder = 0, suma = 0;
        while (cin >> n){
        reminder = n % 10;
        n /= 10;
        suma += reminder;
        cout << n << " IS COOL" << endl;
    }
    if (reminder % 2 == 0) cout << n << " IS COOL" << endl;
    else cout << n << " IS NOT COOL" << endl;
}
