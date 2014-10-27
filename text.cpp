#include <iostream>
#include "date.h"
using namespace std;
int main(){
	Date a(2000,8,14),b;
	Date c[100];
	b.set(2012,2,29);
	a.show();
	b.show();
	c[0].show();
	c[0].set_y(2003);
	c[0].show();
	return 0;
	

}
