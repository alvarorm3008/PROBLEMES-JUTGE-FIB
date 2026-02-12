#include <typeinfo>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Student {
    int idn;
    string name;
    double mark;        // The mark is a value between 0 and 10, or -1 that represents NP
    bool repeater;
};


void information(const vector<Student>& es, double& min, double& max, double& avg){
    max = avg = 0;
    min = 10;
    int tam = es.size();
    int count = 0;
    
    for(int i=0; i<tam; ++i){
        if(not es[i].repeater and es[i].mark != -1){
            if(es[i].mark > max) max = es[i].mark;
            if(es[i].mark < min) min = es[i].mark;
            avg += es[i].mark;
            ++count;
        }
    }
    
    if(count == 0){
        min = max = avg = -1;
    }
    else avg /= double(count);
}
