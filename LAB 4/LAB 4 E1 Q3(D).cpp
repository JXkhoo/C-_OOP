#include <iostream>
using namespace std;
class Date
{
	private: 
		int day;
		int month;
		int year;
	public:
		Date(int,int,int);
		Date();
		
	
		
		int getDay()
		{
			return day;
		}
		int getMonth()
		{
			return month;
		}
		int getYear()
		{
			return year;
		}
		
		
};


Date::Date(int d, int m, int y )
{
	day=d;
	month=m;
	year=y;
};

Date::Date()
{
	day=0;
	month=0;
	year=0;
	
};




int main()
{
	Date birthDate(28,9,1999);
	
	Date *dateptr;
	dateptr=&birthDate;
	

	
	
	
	cout<<"Day"<<birthDate.getDay()<<endl;
	cout<<"Month"<<birthDate.getMonth()<<endl;
	cout<<"Year"<<birthDate.getYear()<<endl;
}

