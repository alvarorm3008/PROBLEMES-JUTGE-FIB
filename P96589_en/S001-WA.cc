#include <iostream>
using namespace std;

int main() {

	char r;
	cin >> r;
	
	if (r >= 0 and r <= 9) cout << "digit" << endl;
	else if ((r >= 'A' and r <= 'Z') or (r >= 'a' and r <= 'z')) cout << "letra" << endl;
	else cout << "res" << endl;

}
