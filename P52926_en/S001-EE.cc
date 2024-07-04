#include <iostream>
#include <string>
using namespace std;

void girar_paraules(string word) {
    while (cin >> word and word != "fi") {
            girar_paraules(word);
            cout << word << endl;
        }
}

int main() {
    string word;
    girar_paraules(word);
}

