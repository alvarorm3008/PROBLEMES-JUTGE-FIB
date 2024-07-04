#include <iostream>
using namespace std;

int main () {
    //pensar la succesio de condicions ifs
    // com hi ha dos diferents declarem 2
    string word;
    string major_word = "";
    string second_word = "";
    
    cin >> major_word >> word;
    
    while (cin >> word) {
        if (word != major_word or word != second_word){
            if (word > major_word){
                second_word = major_word;
                major_word = word;
            }
            else if (word < major_word and word > second_word)
                second_word  = word;
        }

    }
    cout << second_word << endl;
}
