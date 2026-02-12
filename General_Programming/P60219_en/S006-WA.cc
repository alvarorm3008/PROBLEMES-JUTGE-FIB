#include <iostream>
#include <set>
using namespace std;

struct classcomp {
	bool operator()(const string& a, const string& b) const {
		if (a.length() != b.length()) return a.length() < b.length();
		return a < b;
	}
};

typedef set<string>::iterator iterhas;

int main() {
	string s; 
	cin >> s;
	int cont = 1;
	while (s != "QUIT") {
		set<string> has;
		set<string, classcomp> had;
		
		while (s != "END" and s != "QUIT") {
			iterhas it = has.find(s); //auto it = has.find(s);
			if (it == has.end()) {
				has.insert(s);
				had.erase(s);
				/*
				iterhad it1 = had.find(s);
				if (it1 != had.end()) had.erase(it1);
				*/
			}
			else {
				has.erase(it);
				had.insert(s);
			}
			cin >> s;
		}
		cout << "GAME #" << cont<< endl << "HAS:" << endl;
		
		for (iterhas it = has.begin(); it != has.end(); ++it) 
			cout << *it << endl;
		
		cout << endl << "HAD:" << endl;
		for (auto it = had.begin(); it != had.end(); ++it) 
			cout << *it << endl;
		
		if (s != "QUIT") cout << endl;
		cin >> s;
		++cont;
	}
}





