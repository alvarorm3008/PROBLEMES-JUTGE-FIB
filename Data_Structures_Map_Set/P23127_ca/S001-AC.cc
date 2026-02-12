#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		map<string,string> propuesta; //first = propuesta, second = autor
		string prop, nom, voto;
		for (int i = 0; i < n; ++i) {
			cin >> nom >> prop;
			propuesta.insert({prop, nom});
			//propuesta[prop] = nom;
		}
		
		map<pair<string, string>, string> votos; //first.first = nom, first.second = prop, second = SI/NO
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> nom >> voto >> prop;
			votos[{nom, prop}] = voto;
			/*
			auto it = votos.find({nom, prop});
			if (it != votos.end()) it->second = voto;
			else votos.insert({{nom, prop}, voto});
			*/
		}
		
		map<string, pair<int, int>> res;
		for (auto it = votos.begin(); it != votos.end(); ++it) {
			string p = it->first.second;
			if (it->second == "SI") ++res[p].first;
			else ++res[p].second;
		}
		
		for (auto it = res.begin(); it != res.end(); ++it) {
			int nsi = it->second.first;
			int nno = it->second.second;
			if (nsi > nno) 
				cout << it->first << ", de " << propuesta[it->first] << ", que ha guanyat " << nsi << '-' << nno <<endl; 
		}
		cout << string(10, '-') << endl;
	}
}