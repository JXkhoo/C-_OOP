#include<iostream>

using namespace std;

class Contact
{
	private:
		
		string phone;
		
	public:
		
		Contact(string p)
		{
			phone=p;
		}
		
		string getPhone()
		{
			return phone;
		}
};

class Car
{
	private:
		string plate;
		
	public:
		
		Car(string pla)
		{
			plate = pla;
		}
		
		string getPlate()
		{
			return plate;
		}	
};


class Customer
{
	private:
		string name; 
		Contact con;
		Car* car;
	public:
		
		Customer(string n,string p,Car *c)
		:con(p)
		{
			name=n;
			car = c;
		}
		
		Customer(string n,string p)
		:con(p)
		{
			name=n;
		}
		
		string getName()
		{
			return name;
		}
		
		string getPhoneNumber()
		{
			return con.getPhone();
		}
		
		string getPlateNumber()
		{
			return car->getPlate();
		}
}; 

int main()
{
	Car *car1;
	car1= new Car("JSQ245");
	Customer cus[2]={Customer("Ahmad Kamal","015-75769800",car1), 
				   	 Customer("Siti Nurdiana Abdullah","014-8889900")};
				   	 
	for(int i=0;i<2;i++)
	{
		cout<<"Customer's Name : "<<cus[i].getName()<<endl;
		cout<<"Phone Number : "<<cus[i].getPhoneNumber()<<endl; 
		cout<<"Rented Car: "<<cus[i].getPlateNumber()<<endl;
	}
}
