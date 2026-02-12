#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, c = 0;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for(int j = 0; j < n - 1; ++j) {
        if (A[j] == A[n - 1]) ++c;
    } 
    cout << c << endl;
}
