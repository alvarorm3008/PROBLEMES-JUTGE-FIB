#include <iostream>

using namespace std;

int main (){
	
	int n , tot_1 = 0, tot_2 = 0, tot_3 = 0;
	
	cin >> n ;
	
	tot_1 = n % 100 / 10;
	tot_2 = n % 1000 / 100;
	tot_3 = n % 1000 / 100;
	
	cout << tot_1 + tot_2 + tot_3 << endl;
	
	
	
	/*tot_1 = n % 10;
	
	tot_2 = (n % 100) - tot_1;
	tot_3 = (n % 1000) - tot_2 - tot_1;
	
	cout << tot_1 + tot_2 + tot_3 << endl; ;
	
	/* tot 10 - tot 100 == 2 numero
		tot 10 == primer num
		tot 100 - tot 10 == segon num
		tot 100 - tot 100 - tot 10 == tercer num 
	
	
	*/
	
	return 0;
}
