#include <iostream>

using namespace std;

int main(){
	
	int temp;
	cin >> temp;
	
	if (temp >= 30) {
		cout << "it's hot" << endl;
		if (temp == 100)
		cout << "water would boil" << endl;
	}
	else if (temp <= 10) {
		cout << "it's cold" << endl;
		if (temp == 0)
		cout << "water would freeze" << endl;
	}
	else cout << "it's ok" << endl;
	
	
	return 0;
}
