#include <iostream>
using namespace std;


int main() {

	int a1,b1,a2,b2;
	cin >> a1;
	cin >> b1;

	cin >> a2;
	cin >> b2;
	
	if ((b1<a2) or (b2<a1)) cout <<"[]"<<endl;
    
    else if ((a1<=a2) and (b1<=b2)) cout <<"["<<a2<<","<<b1<<"]"<<endl;		

	else if ((a1<=a2) and (b2<=b1)) cout <<"["<<a2<<","<<b2<<"]"<<endl;	
	
    else if ((a1>=a2) and (b1<=b2)) cout <<"["<<a1<<","<<b1<<"]"<<endl;				

	else if ((a1>=a2) and (b2<=b1)) cout <<"["<<a1<<","<<b2<<"]"<<endl;	
	
	}
	
