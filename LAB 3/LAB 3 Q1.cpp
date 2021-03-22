//PT2-SEC03  Assignment 1

//Group 14

// Khoo Jie Xuan
// Putera Syabil
//Pharveish Ail Selvam

#include<iostream>

using namespace std;

double x_amount,y_amount;

class Point
{
	private:
		double x,y;
	
	public:
		
		Point();
		
		Point(double,double);
			 
		void shift(double newValue1,double newValue2)
		{
			x_amount=x+newValue1;
			y_amount=y+newValue2;
				
			cout<<"The new coordinates are"<<endl;
			cout<<"x: "<<x_amount<<endl;
			cout<<"y: "<<y_amount<<endl;
		};
		
		void set_x(double newValue1)
		{	x = newValue1;	};
		
		void set_y(double newValue2)
		{	y = newValue2;	};
		
		double get_x()
		{	return x;	};
		double get_y()
		{	return y;	};	
};

Point::Point()
{
	x=0.0;
	y=0.1;
};

int main()
{
	//Read user input
	double newValue1,newValue2;
	Point p1;
	cout<<"Enter the value of the current coordinates: "<<endl;
	cout<<"x: ";
	cin>>newValue1;
	cout<<"y: ";
	cin>>newValue2;
	
	p1.set_x(newValue1);
	p1.set_y(newValue2);
	
	//P2 will used the initial value as the coordinates
	Point p2;
	cout<<endl;
	cout<<"The initial value of the coordinates: "<<p2.get_x()<<" , "<<p2.get_y()<<endl;
	cout<<endl;
	
	p2.shift(newValue1,newValue2);

	
}
