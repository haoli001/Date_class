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
int Date::ToInt(int yy=1,int mm=1)const{
	int sum=0;
	for(int i=yy;i<y;i++){
		sum+=365+is_p_year(i);
	}
	for(int i=mm;i<m;i++){
		sum+=DayforMonth(y,m);
	}
	sum+=d;
	return sum;
}
void Date::r_set(){
	while(d>DayforMonth(y,m)){//大于
		d-=DayforMonth(y,m);
		m++;
		if(m>12){
			++(y);
			m=1;
		}
	}
	while(d<1){
		m--;
		if(m<1){
			y--;
			m=12;
		}
		d+=DayforMonth(y,m);
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
Date& Date::operator +=(const int v){
	if(v==0)return *this;
	if(v>0){
		d+=v;
		this->r_set();
		return *this;
	}
	else return *this-=(-v);
}
Date& Date::operator -=(const int v){
    if(v==0)return *this;
    if(v>0){
        d-=v;
        this->r_set();
        return *this;
    }
    else return *this+=(-v);
}
Date& Date::operator ++(){
	d++;
	this->r_set();
	return *this;
}
Date  Date::operator ++(int){
    Date b=*this;
    d++;
    this->r_set();
    return b;
}
Date operator -(const Date a,const int v){
	Date b=a;
	if(v==0)return b;
	if(v>0){
		b.d--;
		b.r_set();
		return b;
	}
	else return b+(-v);
}
int operator-(const Date a,const Date b){
	return a.ToInt()-b.ToInt();
}
Date& Date::operator --(){
	d--;
	this->r_set();
	return *this;
}
Date  Date::operator --(int){
    Date b=*this;
    d--;
    this->r_set();
    return b;
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
std::ostream& operator <<(std::ostream &os,const Date &a){
    os<<a.y<<'-'<<a.m<<'-'<<a.d<<std::endl;
    return os;
}
std::istream& operator >>(std::istream &in,Date &a){
    std::string h;
    in>>h;
    Date b(h);
    a=b;
    return in;
}