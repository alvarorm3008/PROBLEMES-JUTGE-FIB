#include <iostream>
using namespace std;

void girant_llista6(int& n, int& cant){
    string x;
    if(cin >> x){
        ++n;
        ++cant;
        girant_llista6(n,cant);
        --n;
        if(n < cant/2) cout << x << endl;
    }
}

int main(){
    int n = 0, count = 0;
    girant_llista6(n,count);
}