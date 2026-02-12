#include <vector>
#include <iostream>
using namespace std;

typedef vector< vector<int> > Matrix;

void swap (int& x, int& y) {
    int z = y;
    y = x;
    x = z;
}
void transpose(Matrix& M){
    int n = M.size();
    for (int i = 0; i < (n -1); ++i)
        for (int j = i + 1; j < n; ++j) {
            swap (M[i] [j], M[j] [i]);
        }
             
}
