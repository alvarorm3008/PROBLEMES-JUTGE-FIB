#include <iostream>
using namespace std;

int main() {
 
    string previ, seg;
    int n, count = 1, ultim = 0;
    
    while (cin >> n) {
        bool creixent = true;
        
        if (n > 0) cin >> previ;
        
        for (int i = 1; i < n; ++i) {
            cin >> seg;
            if (seg < previ) creixent = false;
            previ = seg;
        }
        if (creixent) ultim = count;
        ++count;
    }
    if (ultim != 0) cout << "The last line in increasing order is " << ultim << "." << endl;
    else cout << "There is no line in increasing order." << endl;
}
