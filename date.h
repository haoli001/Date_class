#pragma once
#include <iostream>
#include <string>
#ifndef _DATE_
#define _DATE_
#endif
class Date{
	public:
		Date(int y,int m,int d)
		:y(y),m(m),d(d){
			set(y,m,d);
		}
        Date(const int yyy=19900101){
            int yy=yyy;
            y=yy/10000;
            yy%=10000;
            m=yy/100;
            d=yy%100;
        }
        Date(const std::string h){
            int i=0;
            int tmp=0;
            for(int i=0;i<h.length();i++){
                while(h[i]>='0'&&h[i]<='9'&&i<h.length()){
                    tmp+=h[i]-'0';
                    tmp*=10;
                    i++;
                }
            }
            tmp/=10;
            int yy=tmp;
            int y1=yy/10000;yy%=10000;
            int m1=yy/100;
            int d1=yy%100;
            set(y1,m1,d1);
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
		void set(int yy,int mm,int dd){
			if(yy<=0)yy=1990;
			else y=yy;
			if(mm<=0||mm>12)m=1;
			else m=mm;
			if(dd<=0||dd>DayforMonth(y,m))d=1;
			else d=dd;
		}
		void set_y(int yy){
			set(yy,m,d);
		}
		void set_m(int mm){
			set(y,mm,d);
		}
		void set_d(int dd){
			set(y,m,dd);
		}
        void clear(){
            
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
        friend std::ostream & operator <<(std::ostream &os,const Date &a);
		friend std::istream & operator >>(std::istream &is,Date &a);
	private:
		int y,m,d;
		int DayforMonth(int y,int m)const;
		int ToInt()const;
		void r_set();
};
