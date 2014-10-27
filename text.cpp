#include <iostream>
#include "date.h"
using namespace std;
int main(){
	Date a(20021009),b(90807);
	Date c[100];
	a.show();
	b.show();
	cout<<a.get_year()<<endl;
	cout<<b.get_month()<<endl;
	a.set_m(13);
	a.set_d(40);
	a.show();
		return 0;
	

}
