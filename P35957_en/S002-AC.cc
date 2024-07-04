#include <iostream>
#include <cmath>
using namespace std; 

int main() {
	int n;
	cin >> n;
	n*=2;
	int anna, bernat;

	bool found_b = false, found_a = false;
	cin >> anna;
	int aux = anna, elem = 0, i = 1;
	while (aux != 0) {
        aux/= 10;
        ++elem;
    }
    for (int j = 1; j <= elem/2; ++j) anna /= 10;
    if (elem > 0)anna %= 10;
    if (elem%2 == 0 and elem != 0) found_a = true;
    --n;
	
    while (n != 0 and not found_b and not found_a) {
        int auxi, element = 0;
		if (i%2 != 0) {
            cin >> bernat;
            auxi = bernat;
            while (auxi != 0) {
                auxi/=10;
                ++element;
            }
            for (int j = 1; j <= element/2; ++j) bernat /= 10;
            if (element > 0) bernat = bernat%10;
            if (bernat != anna or (element%2 == 0 and element != 0)) found_b = true;
            ++i;
		}
		else {
            cin >> anna;
            auxi = anna;
            while (auxi != 0) {
                auxi/=10;
                ++element;
            }
            for (int j = 1; j <= element/2; ++j) anna /= 10;
            if (element > 0)anna %= 10;
            if (anna != bernat or (element%2 == 0 and element != 0)) found_a = true;
            ++i;
        }--n;
	}	
        if (found_b) cout << 'A' << endl;
        else if (found_a) cout << 'B' << endl;
        else cout << '=' << endl;
}
