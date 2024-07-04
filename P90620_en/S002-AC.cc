#include <iostream>
using namespace std;

int main (){
    
    int a, b, c;
    cin >> a >> b >> c;
    bool pic = false;
    
    while (c != 0 and not pic){
        pic = (a < b and b > c and b > 3143);
        a = b;
        b = c;
        cin >> c;
    }
    if (pic) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    
}
