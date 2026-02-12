#include <vector>
#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> A(1001);
    
    for (int i = 0; i < n; ++i) {
         int x;
         cin >> x;
         ++A[x - 1000000000];
    }
    
    int tam = A.size();
    for (int i = 0; i < tam; ++i) {
         if (A[i] > 0) cout << 1000000000 + i << ':' << A[i] << endl;
    }
}
