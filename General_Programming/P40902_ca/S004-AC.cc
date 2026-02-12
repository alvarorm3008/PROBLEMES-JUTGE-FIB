#include <iostream>
#include <map>

using namespace std;

int main () {
	map<string, int> m;
	map <string, int>:: iterator it;
	string nom, op;
	while (cin >> nom) {
		cin >> op;
		it = m.find(nom);
		if (it == m.end()) {
			if (op == "leaves" or op == "wins") cout << nom << " is not in the casino" << endl;
		}
		if (op == "enters") {
			if (it == m.end()) m.insert (make_pair (nom, 0));
			else cout << nom << " is already in the casino" << endl;
		}
		else if (op == "leaves") {
			if (it != m.end())cout << nom << " has won " << it->second << endl;
			m.erase(nom);
		}
		else if (op == "wins") {
			int x;
			cin >> x;
			it->second += x;
		}
	}
	cout << "----------" << endl;
	for (it = m.begin(); it != m.end(); ++it) {
		cout << it->first << " is winning " << it->second << endl;
	} 
}
