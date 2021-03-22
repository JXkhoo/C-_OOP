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
	Date sunset(7,35,45);
	

	
	
	
	cout<<sunset.getDay()<<endl;
	cout<<sunset.getMonth()<<endl;
	cout<<sunset.getYear()<<endl;
}

