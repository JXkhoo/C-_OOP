#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class Time
{
	private:
		int hour;
		int minute;
	public:
		Time(int h,int m)
		{
			hour = h;
			minute = m;
		}
		int getHour()
		{
			return hour;
		}
		int getMinute()
		{
			return minute;
		}
};

class Passenger
{
	private:
		string name;
		int age; 
	public:
		Passenger(string n, int a)
		{
			name=n;
			age=a;
		}
		
		void printDetails()
		{
			cout<<"Name:\t"<<name<<"\tAge:\t"<<age;
		}
};


class Flight
{
	private:
		string id;
		string destination;
		Time *depart;
		Time *arrival;
		vector<Passenger>passengerList;
		
	public:
		
		Flight(string i,string d,Time *de,Time *a)
		{
			id=i;
			destination=d;
			depart=de;
			arrival=a;
		} 
		
	
		void printDetails()
		{
	
			cout<<"Flight No:	"<<id<<endl;
			cout<<"Destination:	"<<destination<<endl;
			cout<<"Departure:	"<<depart->getHour()<<":"<<depart->getMinute()<<endl;
			cout<<"Arrival:	"<<arrival->getHour()<<":"<<setfill('0')<<setw(2)<<arrival->getMinute()<<endl;
		}
		
		int addPassengers(const Passenger& p)
		{
				passengerList.clear();
				passengerList.push_back(p);
				return passengerList.size();
		}
};

class Kids:public Passenger
{
	private:
		string parentName;
	public:
		Kids(string n,int a,string p)
			:Passenger(n,a)
		{
			parentName=p;
		}
		void printDetails()
		{
			Passenger::printDetails();
			cout<<"\tParents Name:\t"<<parentName<<endl;
		}
};

class Adult:public Passenger
{
	private:
		string job;
	public:
		Adult(string n,int a,string j)
			:Passenger(n,a)
		{
			job=j;
		}
		void printDetails()
		{
			Passenger::printDetails();
			cout<<"\tJob Title:\t"<<job<<endl;	
		}	
};

int main()
{
	Time departTime(8,10);
	Time arrivalTime(9,00);
	Flight flight("NAS7921","JOHOR BAHRU",&departTime,&arrivalTime);
	flight.printDetails();
	
	int numOfKid,numOfAdult,numOfPassenger;
	numOfKid = flight.addPassengers(Kids("Azmi",3,"Ali"));	
	numOfAdult = flight.addPassengers(Adult("Ali",34,"Lecturer"))+ flight.addPassengers(Adult("Goh",25,"Student"));
	numOfPassenger = numOfKid+numOfAdult;
	
	cout<<"\n\nNumber of Passengers:	"<<numOfPassenger<<endl;
	cout<<"Number of Adults:	"<<numOfAdult<<endl;
	cout<<"Number of Kids:		"<<numOfKid<<endl;
	
	
	Kids kid("Azmi",3,"Ali");
	Adult adult1("Ali",34,"Lecturer");
	Adult adult2("Goh",25,"Student");


	
	cout<<"\n\nPassengers Details:"<<endl;
	adult1.printDetails();
	adult2.printDetails();
	kid.printDetails();	

}


