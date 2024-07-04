#include <iostream>
using namespace std;

int main () {
    
    string n;
    bool begin = false;
    bool end = false;
    bool correct = true;
    int count = 0;
    
    while (cin >> n and correct and not end){
        if (n == "end" and begin) end = true;
        else if (n == "beginning") begin = true;
        else if (n == "end" and not begin) correct = false;
        else {
            if (begin) ++count;
        }
    }
    if(end) cout << count << endl;
    else cout << "wrong sequence" << endl;
}
