#include <iostream>
#include <vector>

using namespace std;

int fix (const vector<int>& v, int a, int e, int d){
  if (e > d) return -1;
  else {
    int m = (e+d)/2;
    if (v[m] + a == m) {
      if (m-1 < e or v[m-1] + a != m-1) return m;
      else return fix(v,a,e,m-1);
    }
    else if (v[m] + a < m) return fix(v,a,m+1,d);
    else return fix(v,a,e,m-1);
  }
}

int main ( ){
  int n;
  int seq = 1;
  while (cin >> n) {
    cout << "Sequence #" << seq << endl;
    vector<int> v(n+1); 
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int a;
      cin >> a;
      int pos = fix(v,a,1,n);
      if (pos == -1) cout << "no fixed point for " << a << endl;
      else cout << "fixed point for " << a << ": " << pos << endl;      
    }
    ++seq;
    cout << endl;
  }
}
