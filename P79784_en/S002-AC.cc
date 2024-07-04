#include <iostream>
using namespace std;

int main() {
	char r;
    int x = 0, y = 0;
    while (cin >> r) {
        if (r == 'n') --y;
        else if(r == 's') ++y;
        else if (r == 'e') ++x;
        else --x;
    }
    cout << '(' << x << ", " << y << ')' << endl;
}
	
