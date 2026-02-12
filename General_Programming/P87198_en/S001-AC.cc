#include <iostream>
using namespace std;

int main(){
    
    int n;
    while (cin >> n){
        int tam = 3*n - 2;
        int bloque2 = n-1;
        int bloque3 = 2*n -1;
        int aux_izq = n -1;
        int aux_der = 2*n -2;
        
        for(int i = 0; i<tam; ++i){
            if (i< bloque2){
                for (int j = 0; j <tam; ++j){
                	if (j < aux_izq) cout << ' ';
                	else if (j<= aux_der) cout << 'X';
            }
            --aux_izq;
            ++aux_der;  
        	}
        	else if (i < bloque3){
        		for (int j = 0; j <tam; ++j) cout << 'X';
			}
			else {
				++aux_izq;
            	--aux_der;
            	
            	for (int j = 0; j< tam; ++j) {
            		if (j < aux_izq) cout << ' ';
            		else if (j <= aux_der) cout << 'X';
            	}
        	}
        	cout << endl;
    	}
    	cout << endl;
	}
}

