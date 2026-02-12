#include <iostream>
using namespace std;


int main () {
	char c;
	int res = 0;
	while (cin >> c){
	if (c == 'a' or c == 'e') c = 'b' - 'a';
	if (c == 'o' or c == 's') c = 'c' - 'a';
	if (c == 'd' or c == 'i' or c == 'n' or c == 'r') c = 'd' - 'a';
	if (c == 'c' or c == 'l' or c == 't' or c == 'u') c = 'e' - 'a';
	if (c == 'm' or c == 'p') c = 'f' - 'a';
	if (c == 'b' or c == 'f' or c == 'g' or c == 'h' or c == 'j' or c == 'q' or c == 'v' or c == 'x' or c == 'y' or c == 'z') c = 'g' - 'a';
	if (c == 'k' or c == 'w') c = 'h' - 'a';
	res += c;
	}
	cout << res << endl;
}
