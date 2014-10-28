#include <iostream>
#include "date.h"
using namespace std;
int main(){
	Date a("20080229"),b(20001010);
	Date c[100];
	a.set_now();
	cout<<a<<endl;
	cout<<a.week_num()<<endl;

	return 0;
}
