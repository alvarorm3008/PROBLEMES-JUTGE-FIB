#include <iostream>

using namespace std;

int main (){

    int x, y, tot = 0 ;
    cin >> x >> y ;
    
    if (x > y){
        int i = x;
        while ( i >= y){
            i--;
            tot = x -y ;
            cout << tot << endl;
        }
    

}
}
