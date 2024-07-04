#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matriu;

const Matriu X = {{1,1}, {1, 0}};


Matriu multiplicacion (const Matriu& a, const Matriu& b, int m) {
    Matriu res (2, vector<int> (2));
    res [0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % m;
    res [0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % m;
    res [1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % m;
    res [1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % m;
}

//post: res = X^n mod m
void exponenciacion (int n, int m, Matriu& res) {
    if (n == 1) res = X;
    else {
        Matriu aux (2, vector<int> (2));
        exponenciacion (n/2, m, aux);
        //Hi: post
        res = multiplicacion(aux, aux, m);
        //A: res = X^n/2 mod m * X^n/2 mod m
        if (n % 2 != 0) res = multiplicacion (res, X, m);
    }
}

int fib (int n, int m) {
    if (n <= 1) return n;
    else {
        Matriu res (2, vector<int> (2));
        exponenciacion (n, m, res);
        return res[0][1]; // res[1][0]
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        cout << fib (n, m) << endl;
    }
}