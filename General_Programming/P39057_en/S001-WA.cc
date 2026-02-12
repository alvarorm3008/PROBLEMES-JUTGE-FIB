#include <iostream> 
#include <cmath>

using namespace std;
int main() {
	
	cout.setf(ios::fixed);
	cout.precision(6); 
	double n(1), x(3), y(4), r(6), rquadrat = 0, areacercle = 0, arearectangle = 0 ;
	string re, c ;
	cin >> n >> re >> x >>  y >> c >> r ;
	

	rquadrat = r * r;
	areacercle = rquadrat * M_PI;
	arearectangle = x * y ;
	cout << arearectangle << endl;
	cout << areacercle << endl;


	
	
	
	
}
