#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> vis_v, vis_c;
string cons, vocal, sol;
int n;

void consonant_vocal (int i) {
    if (i == 2*n) cout << sol << endl;
    else {
        for (int j = 0; j < n; ++j) {
            if (i % 2 == 0) {//toca consonante
                if (not vis_c[j]) {
                    sol[i] = cons[j];
                    vis_c[j] = true;
                    consonant_vocal (i+1);
                    vis_c[j] = false;
                }
            }
            else {//toca vocal
                if (not vis_v[j]) {
                    sol[i] = vocal[j];
                    vis_v[j] = true;
                    consonant_vocal (i+1);
                    vis_v[j] = false;
                }
            }
        }
    }
}

int main () {
    cin >> n >> cons >> vocal;
    vis_v = vector<bool> (n, false);
    vis_c = vector<bool> (n, false);
    sol = string (2*n, ' ');

    consonant_vocal (0);
}