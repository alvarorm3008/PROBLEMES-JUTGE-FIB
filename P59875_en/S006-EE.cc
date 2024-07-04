#include <iostream>

using namespace std;

int main (){

    int x, y, tot = 0, i = 0;
    cin >> x >> y ;
    
    if (x > y){
        i = x;
        while ( i >= y){
            i--;
            tot = x - i ;
            cout << tot << endl;
        }
    

} else if (x<y){
        i = y;
        while ( i <= y){
            i--;
            tot = y - i ;
            cout << tot << endl;
        }
} else cout << x << endl;
}
