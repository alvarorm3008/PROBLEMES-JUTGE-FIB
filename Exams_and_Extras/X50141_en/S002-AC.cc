#include <iostream>
using namespace std;


int fatten(int x) {
    if (x < 10) return x;
    int y = fatten(x/10);
    if (x%10 > y%10) return y*10 + x%10;
    else return y*10 + y%10;
}
