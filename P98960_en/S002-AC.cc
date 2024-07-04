#include <iostream>

using namespace std;

int main(){
    char lletra;
    
    cin>>lletra;
    
    if(lletra>='A' && lletra <='Z') cout<<char(lletra-'A'+'a')<<endl;
    
    else cout<<char(lletra-'a'+'A')<<endl;
    
    
    return 0;
}
