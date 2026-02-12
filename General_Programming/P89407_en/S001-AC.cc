#include <iostream>
#include <vector>
using namespace std;

void escribir_numero(int x, int i){
    if(x < i){
        if(x < 10) cout << x;
        else cout << char(x - 10 + 'A');
    }
    else{
        escribir_numero(x/i,i);
        int aux = x%i;
        if(aux < 10) cout << aux;
        else cout << char(aux - 10 + 'A');
    }
}


bool igual_digitos(int x, int y, int i){
    vector<int> aux(i,0);
    int result = x * y;
    while(result > 0){
        if(x > 0) ++aux[x%i];
        if(y > 0) ++aux[y%i];
        --aux[result%i];
        x /= i;
        y /= i;
        result /= i;
    }
    
    for(int k=0; k<aux.size(); ++k){
        if(aux[k] != 0) return false;
    }
    return true;
}

void Stable_products(int x, int y){
    cout << "solutions for " << x << " and " << y << endl;
    bool encontrado = false;
    
    for(int i=2; i<=16; ++i){
        if(igual_digitos(x,y,i)){
            encontrado = true;
            escribir_numero(x,i);
            cout << " * ";
            escribir_numero(y,i);
            cout << " = ";
            escribir_numero(x*y,i);
            cout << " (base " << i << ")" << endl;
        }
    }
    
    if(not encontrado) cout << "none of them" << endl;
    
}

int main(){
    int x, y;
    
    while(cin >> x >> y){
        Stable_products(x,y);
        cout << endl;
    }
}
