#include <iostream>
#include <vector>
using namespace std;

void leer_matrix(vector< vector<int> >& m){
    int f, c;
    cin >> f >> c;
    m = vector< vector<int> >(f,vector<int>(c));
    for(int i=0; i<f; ++i)
        for(int j=0; j<c; ++j)
            cin >> m[i][j];
}

void Rows_and_columns(const vector< vector<int> >& m){
    string x;
    while(cin >> x){
        if(x == "row"){
            int y;
            cin >> y;
            cout << "row " << y << ":";
            int aux = m[0].size();
            for(int i=0; i<aux; ++i)  cout << " " << m[y-1][i];
            cout << endl;
            
        }
        else if(x == "column"){
            int y;
            cin >> y;
            cout << "column " << y << ":";
            int aux = m.size();
            for(int i=0; i<aux; ++i)  cout << " " << m[i][y-1];
            cout << endl;
            
        }
        else if(x == "element"){
            int y,z;
            cin >> y >> z;
            cout << "element " << y << " " << z << ": " << m[y-1][z-1] << endl;
        }
    }
}

int main(){
    vector< vector<int> > M;
    leer_matrix(M);
    Rows_and_columns(M);
}
