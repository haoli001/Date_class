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
	a.show();
	a+=1;
	a.show();
	b=a-1;
	b.show();
	a+=(-1);
	a.show();
	++a;
	a.show();
	cout<<a-b<<endl;


	c[0].show();
	c[0].set_y(2003);
	c[0].show();
	return 0;
	

}
