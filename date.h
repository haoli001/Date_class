#pragma once
#include <iostream>
#ifndef _DATE_
#define _DATE_
#endif
class Date{
	public:
		Date(int y=1990,int m=1,int d=1)
		:y(y),m(m),d(d){
			if(y<=0)y=1990;
			if(m<=0||m>12)m=1;
			if(d<=0||d>DayforMonth(y,m))d=1;
		}
		int get_year(){
			return y;
		}
		int get_month(){
			return m;
		}
		int get_day(){
			return d;
		}
		bool is_p_year()const{
			return y%400?(y%100?(y%4?0:1):0):1;
		}
		bool is_p_year(const int yy)const{
			return yy%400?(yy%100?(yy%4?0:1):0):1;
		}
		void show(){
			std::cout<<y<<'-'<<m<<'-'<<d<<std::endl;
		}
		void set(int yy,int mm,int dd){
			y=yy;m=mm;d=dd;
		}
		void set_y(int yy){
			y=yy;
		}
		void set_m(int mm){
			m=mm;
		}
		void set_d(int dd){
			d=dd;
		}
		Date operator += (const int c);
		friend Date operator + (const int v,const Date a);
		friend Date operator + (const Date a,const int v);
		friend Date operator ++(Date &a);
		friend Date operator - (const Date a,const int v);
		friend int  operator - (const Date a,const Date b);
		friend Date operator --(Date &a);
		friend bool operator > (const Date a,const Date b);
		friend bool operator >=(const Date a,const Date b);
		friend bool operator < (const Date a,const Date b);
		friend bool operator <=(const Date a,const Date b);
		friend bool operator ==(const Date a,const Date b);
		friend bool operator !=(const Date a,const Date b);
		//friend std::odtream & operator <<(std::ostream &os,const Date &a);
		//friend std::istream & operator >>(std::istream &is,const Date &a);
	private:
		int y,m,d;
		int DayforMonth(int y,int m)const;
		int ToInt()const;
		void r_set();
};
