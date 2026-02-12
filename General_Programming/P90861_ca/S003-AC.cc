#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<queue<string>> Conj_colas;

void leer_colas(Conj_colas& cj, int n) {
	string s;
	getline(cin, s);
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		istringstream ss(s);
		string nom;
		while (ss >> nom) cj[i].push(nom);
	}
}

void escribir_cola(Conj_colas& cj, int n) {
	for (int i = 0; i < n; ++i) {
		cout << "cua " << i+1 << ':';
		while (not cj[i].empty()) {
			cout << ' ' << cj[i].front(); 
			cj[i].pop();
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	
	Conj_colas cj(n);
	leer_colas(cj, n);
	
	cout << "SORTIDES" << endl << "--------" << endl; //string(8, '-')
	string op;
	while (cin >> op) {
		if (op == "ENTRA") {
			int cola;
			string nom;
			cin >> nom >> cola;
			if (cola >= 1 and cola <= n) cj[cola-1].push(nom);
		}	
		else {
			int cola;
			cin >> cola;
			if (cola >= 1 and cola <= n and not cj[cola-1].empty()) {
				cout << cj[cola-1].front() << endl;
				cj[cola-1].pop();
			}
		}	
	}
	
	cout << endl << "CONTINGUTS FINALS" << endl << string(17, '-') << endl;
	escribir_cola(cj, n); 
}
