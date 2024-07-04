#include <typeinfo>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Estudiant {
    int dni;
    string nom;
    double nota;        // The mark is a value between 0 and 10, or -1 that represents NP
    bool repetidor;
};


void informacio(const vector<Estudiant>& es, double& min, double& max, double& mitj){
    max = mitj = 0;
    min = 10;
    int tam = es.size();
    int count = 0;
    
    for(int i=0; i<tam; ++i){
        if(not es[i].repetidor and es[i].nota != -1){
            if(es[i].nota > max) max = es[i].nota;
            if(es[i].nota < min) min = es[i].nota;
            mitj += es[i].nota;
            ++count;
        }
    }
    
    if(count == 0){
        min = max = mitj = -1;
    }
    else mitj /= double(count);
}
