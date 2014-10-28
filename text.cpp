#include <iostream>
#include "date.h"
using namespace std;
int main(){
	Date a("20080229"),b(20001010);
	Date c[100];
	cout<<a<<endl;
	cout<<a.y_day()<<endl;
	cout<<a.ny_day()<<endl;

	return 0;
}
