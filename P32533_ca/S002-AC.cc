#include <iostream>

using namespace std;

int main (){
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            int aux = i + j + 1;
            if (aux < n) cout << '+';
            else if (aux > n) cout << '*';
            else cout << '/';
        }
        cout << endl;
    }
}

