#include <iostream>

using namespace std;

int main(){
	int count = 0;
	char  r;
    cin >> r;
	while (r != '.'){
		if (r == 'a') ++count;
        cin >> r;
	} 
	if (count >= 1) cout << "yes" << endl;
    else cout << "no" << endl;
}
