#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Row;
typedef vector<Row> Matrix;

void re_0(vector< vector<int> >& v, int x, int y, int& count){
    int f = v.size();
    int c = v[0].size();
    int i = x;
    bool found_one = false;
    while (i < f and v[i][y] != 0) {
        int j = y;
        while(j < c and v[i][j] != 0) {
            v[i][j] = 0;
            found_one = true;
            ++j;
        }
        ++i;
    }
    if (found_one) ++count;
}

int main() {
    int f, c;
     while (cin >> f >> c) {
         Matrix M(f, Row(c));
     for (int i = 0; i < f; ++i)
         for (int j = 0; j < c; ++j)
             cin >> M [i][j];
     int count = 0;
        for (int i = 0; i < f; ++i)
             for (int j = 0; j < c; ++j)
                 if (M[i][j] != 0) re_0 (M, i, j, count);
        cout << count << endl;
    } 
}
