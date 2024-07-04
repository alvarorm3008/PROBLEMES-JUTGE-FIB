#include <iostream>

using namespace std;

int main(){
    
    double x;
    cin>>x;
    
    if(x == int(x))
        cout<<x<<" "<<x<<" "<<x<<endl;
    else
        cout<<int(x)<<" "<<int(x)+1<<" "<<int(x+0.5)<<endl;

    
    
    return 0;
}
