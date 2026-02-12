#include <iostream>
#include <map>
using namespace std;


int main() {
  map<string, int> M;
  char c;
  while (cin >> c) {
    if (c == 'N') {
      cout << "number: " << M.size() << endl;
    }
    else if (c == 'D') {
      string nif;
      int money;
      cin >> nif >> money;
      map<string, int>::iterator it;
      it = M.find(nif);
      if (it != M.end()) it->second += money; 
      else {
        M.insert ({nif, money});
      }
    }
    else if (c == 'Q') {
      string nif;
      cin >> nif;
      map<string, int>::iterator it;
      it = M.find(nif);
      if (it != M.end()) cout << it->second << endl;
      else cout << -1 << endl;
    }
    else if (c == 'P') {
      map<string, int>::iterator it;
      int cont = 0;
      for (it = M.begin(); it != M.end(); ++it) {
        if (it->first[7] % 2 == 0) {
            if (cont != 0) {
                cout << ' ';
            }
            cout << it->first;
            ++cont;
        }
      }
      cout << endl;
    }
    else { // c == 'L'
      auto it = M.rbegin();
      if (it != M.rend()) cout << it->first << ' ' <<  it->second << endl;
      else cout << "NO LAST NIF" << endl;
    }
  }
}
