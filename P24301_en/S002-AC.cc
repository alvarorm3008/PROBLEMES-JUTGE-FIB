#include <iostream>
#include <vector>
using namespace std;

vector<int> concatenation(const vector<int>& v1, const vector<int>& v2) {
    int tam1 = v1.size();
    int tam2 = v2.size();
    vector<int> resultant(tam1 + tam2);
    for (int i = 0; i < tam1; ++i) resultant[i] = v1[i];
    for (int i = 0; i < tam2; ++i) resultant[i + tam1] = v2[i];
    return resultant;
}
int main() {
  int n1;
  while (cin >> n1) {
    vector<int> V1(n1);
    for (int i = 0; i < n1; ++i) cin >> V1[i];
    int n2;
    cin >> n2;
    vector<int> V2(n2);
    for (int i = 0; i < n2; ++i) cin >> V2[i];
    vector<int> res = concatenation(V1, V2);
    cout << res.size() << endl;
    for (int i = 0; i < (int)res.size(); ++i) cout << " " << res[i];
    cout << endl;
  }
}