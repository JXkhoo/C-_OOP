//PT2-SEC03  Assignment 1

//Group 14

// Khoo Jie Xuan
// Putera Syabil
//Pharveish Ail Selvam

#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

double f1,f2,f3;
double numerator1,denominator1,numerator2,denominator2;
char c;	

class fraction
{
	private:
		int num,denom;
	
	public:
		
		void setNum(double numerator3)
		{
			num=numerator3;
		};
		
		void setDenom(double denominator3)
		{
			denom=denominator3;
		};
		
		void multiply(double n1,double d1,double n2,double d2)
		{
			num = n1 * n2;
   			denom = d1 * d2;	
		};
		
		void divide(double n1,double d1,double n2,double d2)
		{
			num = n1 * d2;
    		denom = n2 * d1;
		};
		
		void add(double n1,double d1,double n2,double d2)
		{
			num = ((n1*d2) + (n2*d1));
    		denom = d1 * d2;
		};
		
		void subtract(double n1,double d1,double n2,double d2)
		{
			num = (n1*d2) - (n2*d1);
  			denom = d1 * d2;
		};
		
		void readFrac()
		{
				
 			cout<<"Enter 1st fraction: "<<endl;
			cout<<"Enter numerator / denominator: ";
			cin>>numerator1>>c>>denominator1;
			f1=numerator1/denominator1;
			cout<<"Enter 2nd fraction: "<<endl;
			cout<<"Enter numerator / denominator: ";
			cin>>numerator2>>c>>denominator2;
			f2=numerator2/denominator2;
				
		};
		
		void displayFrac(char i)
		{
			
			switch(i)
			{
				case 'm': cout<<numerator1<<c<<denominator1<<" * "<<numerator2<<c<<denominator2;break;
				case 'd': cout<<numerator1<<c<<denominator1<<" / "<<numerator2<<c<<denominator2;break;
				case 'a': cout<<numerator1<<c<<denominator1<<" + "<<numerator2<<c<<denominator2;break;
				case 's': cout<<numerator1<<c<<denominator1<<" - "<<numerator2<<c<<denominator2;break;
			}
			
		};
		
		double getNum()
		{
			return num;
		};
		
		double getDenom()
		{
			return denom;
		};
 } ;
 
 
 int main()
 {
 	double num3=0,denom3=0;
 	
	fraction f;
	
	//Read user input
	f.readFrac();

	//Set numerator and denomenator of the answer
	f.setNum(num3);
	f.setDenom(denom3);
	
	//Start calculation
	f.multiply(numerator1, denominator1, numerator2, denominator2);
	f.displayFrac('m');
	cout<<" = "<<f.getNum()<<"/"<<f.getDenom()<<endl;
	
	f.divide(numerator1, denominator1, numerator2, denominator2);
	f.displayFrac('d');
	cout<<" = "<<f.getNum()<<"/"<<f.getDenom()<<endl;
	
	f.add(numerator1, denominator1, numerator2, denominator2);
	f.displayFrac('a');
	cout<<" = "<<f.getNum()<<"/"<<f.getDenom()<<endl;
	
	f.subtract(numerator1, denominator1, numerator2, denominator2); 
	f.displayFrac('s');
	cout<<" = "<<f.getNum()<<"/"<<f.getDenom()<<endl;
 	
 
	 
 }
