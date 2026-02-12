#include <iostream>
using namespace std;

void noms_rev() {
    string s;
    if (cin >>s) {
        noms_rev();
    cout << s << endl;
    }
}
int main() {
    noms_rev();
}