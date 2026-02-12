#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Sudoku;

bool check_sudoku(const Sudoku& s){
    int tam1 = s.size();
    int tam2 = s[0].size();
    
    /* PRIMERO COMPROBAMOS QUE ELEMENTO NO SE REPITA EN 
       LA MISMA FILA Y COLUMNA */
    for(int i=0; i<tam1; ++i){
        
        /* creamos dos vectores booleanos que verificarán que no
         * se repita el elemento en la fila y columna; y los volvemos */
        vector<bool> horizontal(9,false);
        vector<bool> vertical(9,false);
        
        for(int j=0; j<tam2; ++j){
            
            /* verificar si elemento se repite en fila */
            int aux_h = s[i][j];
            if(not horizontal[aux_h-1]) horizontal[aux_h-1] = true;
            else return false;
            
            /* verificar si elemento se repite en columna
               notar el cambio de "i" por "j" para lograr 
               el recorrido por columna */
            int aux_v = s[j][i];
            if(not vertical[aux_v-1]) vertical[aux_v-1] = true;
            else return false;
        }
    }
    
    /*DESPUES COMPROBAMOS QUE ELEMENTO NO SE REPITA EN 
      CADA UNA DE LAS 9 REGIONES DEL SUDOKU */
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            
            /* creamos un vector booleano para verificar presencia del elemento */
            vector<bool> presente(9,false);
            
            for(int m=3*i; m<(3*i + 3); ++m){
                for(int n=3*j; n<(3*j + 3); ++n){
                    int aux = s[m][n];
                    if(not presente[aux-1]) presente[aux-1] = true;
                    else return false;
                }
            }
        }
    }
    
    return true;
}

void leer_sudoku(Sudoku& s){
    s = Sudoku(9,vector<int>(9));
    for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j)
            cin >> s[i][j];
}

void solution_of_a_Sudoku(Sudoku& s){
    int n;
    cin >> n;
    for(int ii=0; ii<n; ++ii){
        leer_sudoku(s);
        if(check_sudoku(s)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}

int main(){
    Sudoku s;
    solution_of_a_Sudoku(s);
}
