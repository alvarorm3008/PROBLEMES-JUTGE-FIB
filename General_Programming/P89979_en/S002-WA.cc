#include <iostream>
using namespace std;

int main () {
    
    int n;
    int count = 0;
    bool ordenat = false;
    
    while (not ordenat and cin >> n){
        ++count;
        ordenat = true;
        
        if (n > 0){
            string ant, sig;
            cin >> ant;
            int pal = 1;
            
            while (pal < n){
                ++pal;
                cin >> sig;
                
                if (sig < ant){
                    ordenat = false;
                        
                    while (pal < n){
                        ++pal;
                        cin >> sig;
                        }
                    }
                    else ant = sig;
            }
        }
    }
    if (ordenat) cout << "The first line in increasing order is " << count << " . " << endl;
    else cout << "There is no line in increasing order." << endl;
}
