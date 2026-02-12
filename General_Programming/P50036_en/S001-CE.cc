#include<iostream>
#include<vector>
using namespace std;
// Definition of a polynomial (the coefficient of degree i
// is stored in location i of the vector).
typedef vector<double> Polynomial;
// Pre: -
// Returns the evaluation of P(x)
double PolyEval(const Polynomial& P, double x) {
double eval = 0;
int degree = P.size() - 1;
for (int i = degree; i >= 0; --i) {
eval = eval*x + P[i];
}
return eval;
}
