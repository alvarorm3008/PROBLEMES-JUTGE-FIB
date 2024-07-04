#include <iostream>
using namespace std;

//Pre: en el canal de lectura hay una secuencia no vacia de naturales
//     estrictamente positivas acabada en 0
//Post: el parámetro max tendrá el valor más grande que aparece en la secuencia
//      y el parámetro lpos tiene que indicar la última posición donde
//      aparece el valor máximo.

void infoSequence(int& max, int& lpos) {
    cin >> max;
    lpos = 1;

    int n;
    int pos = 1;
    cin >> n;
    while (n != 0) {
        ++pos;
        if (n >= max) {
            max =n;
            lpos = pos;
        }
        cin >> n;
    }
}

int main() {
    int max, lpos;
    infoSequence(max, lpos);

    int n, pos;
    pos = 0;
    bool trobat = false;
    cin >> n;
    while (n != 0 and not trobat) {
        ++pos;
        if (n == max) trobat = true;
        cin >> n;
    }
        cout << max << ' ' << lpos << ' ';
        if (not trobat) cout << '-' << endl;
        else cout << pos << endl;
}
