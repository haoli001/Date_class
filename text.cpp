#include <iostream>
#include "date.h"
using namespace std;
int main(){
	Date a(2000,8,14),b;
	Date c[100];
	b.set(2012,2,29);
	a.show();
	b.show();
	cout<<a.get_year()<<endl;
	cout<<b.get_month()<<endl;
	a.set_m(13);
	a.set_d(40);
	a.show();
	b.set_d(-1);
	b.show();

	c[0].show();
	c[0].set_y(2003);
	c[0].show();
	return 0;
	

}
