#include <iostream>
using namespace std;

int main (){

    int filas, columnas, suma = 0;
    char s;
    
    cin >> filas >> columnas;
    
    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
            cin >> s;
            if ((i + j) % 2 == 0) suma = s - '0';
        }
    }
    cout << suma << endl;
}
