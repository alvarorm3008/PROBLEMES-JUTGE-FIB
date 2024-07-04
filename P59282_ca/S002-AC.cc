#include <iostream>
#include <queue>
using namespace std;

int main () {
    cout.setf (ios::fixed);
    cout.precision (4);

    priority_queue<int, vector<int>, greater<int>> pq;

    string op;
    int n, max, suma = 0, cont = 0;

    while (cin >> op) {
        if (op == "number") {
            cin >> n;
            pq.push(n);
            suma += n;
            if (cont == 0) max = n;
            else if (max < n) max = n;
            ++cont;
        }
        else {
            if (cont != 0) {
                suma -= pq.top();
                --cont;
                pq.pop();
            } 
        }
        if (pq.empty()) cout << "no elements" << endl;
        else {
            cout << "minimum: " << pq.top() << ", maximum: " << max << ", average: " << double (suma)/cont << endl;
        }
    }
}