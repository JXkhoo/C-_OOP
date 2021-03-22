//PT2-SEC03  Assignment 1

//Group 14

// Khoo Jie Xuan
// Putera Syabil
//Pharveish Ail Selvam


#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

//define value of PI
const double PI=3.142; 

class Cone
{
	private:
		double radius, height;
		
	public:
		void set_R_Data(double r);
		
		void set_H_Data(double h);
		
		double get_R()const
		{
			return radius;	
		}
		
		double get_H()const
		{
			return height;
		}

		double baseArea()
		{
			return PI*radius*radius;
		};
		
		double volume(double basearea)
		{
			return ((1/3.0)*basearea*height);
		};
		
		void displayData(double rad,double hei, double base_area, double vol);
		 
};

void Cone::set_R_Data(double r)
{
	radius=r;
}
void Cone::set_H_Data(double h)
{
	height=h;
}


void Cone::displayData(double rad,double hei, double base_area, double vol)
{
	cout<<"The radius of the cone is "<<rad<<endl;
	cout<<"The height of the cone is "<<hei<<endl;
	cout<<"The base area of the cone is "<<fixed<<setprecision(2)<<base_area<<endl;
	cout<<"The volume of the cone is "<<fixed<<setprecision(2)<<vol<<endl;
};


int main()
{
	Cone cnl;
	double ini_radius,ini_height;
	
	//Ask for user input 
	cout<<"Enter the radius : ";
	cin>>ini_radius;
	cout<<"Enter the height : ";
	cin>>ini_height;
	cout<<endl; 
	
	//Calculate 
	cnl.set_R_Data(ini_radius);
	cnl.set_H_Data(ini_height);
	
	double base_area = cnl.baseArea();
	
	double vol = cnl.volume(base_area);
	
	double rad = cnl.get_R();
	
	double hei = cnl.get_H();
	
	//Display all the data 
	cnl.displayData(rad,hei, base_area,vol);
}
