#include <iostream>
using namespace std;

int main(){
    
    char r;
    int count = 0;
    bool correct = true;
    
    while (cin >> r and correct){
        if (r == '(') ++count;
        else --count;
        if (count < 0) correct = false;
    }
    
    if (correcte) cout << "yes" << endl;
    else cout << "no" << endl;

}
