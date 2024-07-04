#include <iostream>
using namespace std;

void ordre_invers() {
    string s;
    cin >> s;
    if (s != "end") {
        ordre_invers();
        cout << s << endl;
    }
}

int main() {
    ordre_invers();
}
