#include <iostream>
using namespace std;

int main() {
	
	char x, a = ' ', b = ' ', c = ' ', d = ' ';
	cin >> x;
	bool found = false;
	
	while (x != '.' and not found){
		if (a == 'h' and b == 'e' and c == 'l' and d == 'l' and x == 'o' ) found = true;
		a = b;
		b = c;
		c = d;
		d = x;
		
		cin >> x;
	}
	if (found) cout << "hello" << endl;
	else cout << "bye" << endl;
}
