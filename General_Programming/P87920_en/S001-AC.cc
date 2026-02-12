#include <vector>
#include <iostream>
using namespace std;

string equal_suma(const vector<int>& A, int suma) {
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == suma - A[i]) return "YES";
    }
    return "NO";
}

int main() {
    int n;
    while (cin >> n) {
        int suma = 0;
        vector<int> A(n); //declaramos vector de tamaño 'n'
        for (int i = 0; i < n; ++i) {
            cin >> A[i]; //forma para leer un vector
            suma += A[i]; // sumas todos los elementos del vector
        }
        cout << equal_suma(A,suma) << endl;
    }
}
