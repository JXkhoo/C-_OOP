//Group 14
//Lab exercise 4 exercise 3 No 2

#include <iostream>
#include <string>

using namespace std;
const int numMonth=12;
string m[numMonth]={"January","February","March","April","May","June","July","August","September","October","November","December"};
string month ;

class Month
{
	private:
		string name;;
		int monthNumber;
		
	public:
		Month(string a)
		{
			setName(a);
			setmonthNumber(a); 
		}	
		
		void setName(string a)
		{	name = a;	}
		void setmonthNumber(string a)
		{	
			if(a=="January")monthNumber=1;
			else if(a=="February")monthNumber=2;
			else if(a=="March")monthNumber=3;
			else if(a=="April")monthNumber=4;
			else if(a=="May")monthNumber=5;
			else if(a=="June")monthNumber=6;
			else if(a=="July")monthNumber=7;
			else if(a=="August")monthNumber=8;
			else if(a=="September")monthNumber=9;
			else if(a=="October")monthNumber=10;
			else if(a=="November")monthNumber=11;
			else if(a=="December")monthNumber=12;
		}
		
		string getMonthName() 
		{	return name;	}
		
		int getMonthNumber()
		{	return monthNumber;	}	
		
		Month &operator ++();	
		Month operator ++(int);	
		friend ostream &operator <<(ostream &output,const Month &t);	
		friend istream &operator >>(istream &input,Month &t);
					
};

Month& Month::operator ++()
{
	if(monthNumber!=12)this->name=m[monthNumber];
	else this->name=m[0];
	return *this;
}

Month Month::operator ++(int)
{
	
	if(monthNumber!=12)++ monthNumber;
	else monthNumber=1;
	return *this;
}

ostream &operator <<(ostream &output,Month &t)
{
	output<<"The month that you entered is "<<t.getMonthName()<<" which is "<<t.getMonthNumber()<<endl;
	++t;
	t++;
	output<<"The following month is "<<t.getMonthName()<<" which is "<<t.getMonthNumber()<<endl;
	return output;
}

istream &operator >>(istream &input,Month &t)
{
	input>>month;
	return input;
}

int main()
{

	string month;	
	cout<<"Enter the month (January) : ";
	cin>>month;
	Month first(month);
	cout<<first;
	
}

