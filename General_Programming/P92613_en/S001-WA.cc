#include <iostream>

using namespace std;

int main(){
    
    double x;
    int b =int(x);
    int c =int(x+0.5);
    cin>>x;
    
    if(x == int(x))
        cout<<x<<" "<<x<<" "<<x<<endl;
    else
        cout<<b<<" "<<b+1<<" "<<c<<endl;

    
    
    return 0;
}
