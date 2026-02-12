#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tablero;

void calcular_next (int i, int j, int n, int m, int&ni, int& nj) {
    if (j+1 == m) {
        ni = i+1;
        nj = 0;
    }
    else {
        ni = i;
        nj = j+1;
    }
}

int calcular_LOL (Tablero& sol, int i, int j, int n, int m, int num) {
    if (i == n) return num;
    int ni, nj;
    calcular_next (i, j, n, m, ni, nj);

    sol[i][j] = 'O';
    int num_o = calcular_LOL (sol, ni, nj, n, m, num);
    //el numero maximo de LOL poniendo una O en la pos i, j
    sol[i][j] = 'L';
    int num_aux = 0;

    //si hay lol en horizontal
    if ( j >= 2 and sol[i][j-1] == 'O' and sol[i][j-2] == 'L') ++num_aux;
    //si hay lol en la diagonal izquierda
    if (i >= 2 and j >= 2 and sol[i-1][j-1] == 'O' and sol[i-1][j-2] == 'L') ++num_aux;
    //si hay lol en vertical
    if (i >= 2 and sol[i-1][j] == 'O' and sol[i-2][j] == 'L') ++num_aux;
    //si hay lol en diagonal derecha
    if (i >= 2 and j+2 <= m-1 and sol[i-1][j+1] == 'O' and sol[i-1][j+2] == 'L') ++ num_aux;

    int num_l = calcular_LOL (sol, ni, nj, n, m, num);
    //el numero maximo de LOL poniendo una L en la pos i, j
    return max (num_o, num_l);

}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Tablero sol (n, vector<char> (m));
        cout << calcular_LOL (sol, 0, 0, n, m, 0) << endl;
    }
    
}