#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

string Pairs_of_sequence(const vector<int>& A) {
    int tam = A.size() - 1;
    int tam_2 = A.size();
    for (int i = 0; i < tam; ++i) {
        for (int j = i + 1; j < tam_2; ++j) {
            if(is_prime(A[i] + A[j])) return "yes";
        }
    }
    return "no";
}

int main() {
    int n;
    while(cin >> n) {
        vector<int> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        cout << Pairs_of_sequence(A) << endl;
    }
}
