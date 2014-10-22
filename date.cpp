/***
  日期类
 ***/
#include <iostream>
#include "date.h"
// 得到每个月的天数
int Date::DayforMonth(int y,int m)const{
	int d=0;
	switch(m){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			d=31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			d=30;
			break;
		case 2:
			d=28+is_p_year(y);
			break;
	}
	return d;
}
int Date::ToInt()const{
	int sum=0;
	for(int i=1;i<y;i++){
		sum+=365+is_p_year(i);
	}
	for(int i=1;i<m;i++){
		sum+=DayforMonth(y,m);
	}
	sum+=d;
	return sum;
}
void Date::r_set(){
	while(*this->d>*this->DayforMonth(*this->y,*this->m)){//大于
		*this->d-=*this->DayforMonth(*this->y,*thi->.m);
		*this->m++;
		if(*this->m>12){
			++(*this->y);
			*this->m=1;
		}
	}
	while(*this->d<1){
		*this->m--;
		if(*this->m<1){
			*this->y--;
			*this->m=12;
		}
		*this->d+=*this->DayforMonth(*this->y,*this->m);
	}
}
////////////日期加天数
Date operator + (const int v,const Date a){
	Date d=a;
	if(v==0) return d;
	if(v>0){
		d.d+=v;
		d.r_set();
		return d;
	}
	return d-(-v);
}
Date operator +(const Date a,const int v){
	return v+a;
}
Date Date::operator +=(const int c){
	if(v==0)return *this;
	if(v>0){
		a.day++;
		a.r_set();
		return a;
	}
	else return a-=(-v);
}
Date operator ++(Date &a){
	a.d++;
	a.r_set();
	return a;
}
Date operator -(const Date a,const int v){
	Date b=a;
	if(v==0)return b;
	if(v>0){
		b.d--;
		b.r_set();
		return b;
	}
	else return d+(-v);
}
int operator-(const Date a,const Date b){
	return a.ToInt()-b.ToInt();
}
Date operator --(Date &a){
	--a.d;
	a.r_set();
	return a;
}
bool operator ==(const Date a,const Date b){
	return a.ToInt()==b.ToInt();
}
bool operator !=(const Date a,const Date b){
	return !(a==b);
}
bool operator >(const Date a,const Date b){
	return a.ToInt()>b.ToInt();
}
bool operator >=(const Date a,const Date b){
	return a>b||a==b;
}
bool operator <(const Date a,const Date b){
	return !(a>=b);
}
bool operator <=(const Date a,const Date b){
	return a<b||a==b;
}
int main(){
	Date a,b;

}
