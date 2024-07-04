#include <iostream>
using namespace std;

int main () {
    
    string first;
    string words;
    cin >> first;
    int conteo_final = 1;
    int conteo_actual = 1;
    
    while (cin >> words){
        if (words == first){
            ++conteo_actual;
            if (conteo_final < conteo_actual) conteo_final = conteo_actual;
        }
        else conteo_actual = 0;
    }
    cout << conteo_final << endl;
}
