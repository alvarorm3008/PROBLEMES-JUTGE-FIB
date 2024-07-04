#include <iostream>
#include <set>
using namespace std;

struct classcomp {
	bool operator() (const string& a, const string& b) const {
		if (a.length() != b.length()) return a.length() < b.length();
		return a < b;
	}
};

typedef set<string>::iterator ithas;
typedef set<string, classcomp>::iterator ithad;

int main() {
	string s;
	int game = 1;
	
	while (s != "QUIT") {
		set<string> has; //orden alfabetico
		set<string, classcomp> had; //orden long que lo define classcomp
		
		cin >> s;
		while (s != "END" and s != "QUIT") {
			ithas it1 = has.find(s);
			if (it1 != has.end()) {
				has.erase(it1);
				had.insert(s);
			}
			else {
				has.insert(s);
				ithad it2 = had.find(s);
				if (it2 != had.end()) had.erase(it2);
			}
			cin >> s;
		}
		if (game > 1) cout << endl;
		cout << "GAME #" << game << endl << "HAS:" << endl;
		for (ithas it = has.begin(); it != has.end(); ++it) 
			cout << *it << endl;
		cout << endl << "HAD:" << endl;
		for (ithad it = had.begin(); it != had.end(); ++it) 
			cout << *it << endl;
		++game;
	}
}

