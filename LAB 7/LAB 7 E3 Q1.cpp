#include <iostream>
#include <string>
using namespace std;

class Address
{
	private:
		string registrar;
		string country;
		
	public:
		Address(string r,string c)
		{
			set(r,c);
		}
		
		void set(string r,string c)
		{
			this->registrar =r;
			this->country=c;
		}
		
		void print()const
		{	cout<<"Register at: "<<registrar<<","<<country<<endl;
		}
		
};


class Ship
{
	private:
		string name;
		string yearMade;
		Address *add;
		
	public:
		Ship()
		{
			name="no input";
			yearMade="No input";
			
		}
		
		void print()const
		{
			cout<<"Ship Name : "<<name<<endl;
			cout<<"Year Built: "<<yearMade<<endl;
			add->print();
		}
		
		
		void read(string n,string y,Address *a)
		{
			name=n;
			yearMade=y;
			add=a;
		}
};


int main()
{
	int num=20;
	Ship s[num];	
	int choice;
	int i=0;
	Address *add;

	string name,year,regist,country;
			
	do
	{
	
	cout<<"=====MENU====="<<endl;
	cout<<"1. Add a ship"<<endl;
	cout<<"2. Display ship"<<endl;
	cout<<"3. Exit"<<endl;
	cin>>choice;
	cin.ignore();
			
	if(choice==1)
 	{
			cout<<"<<<Enter the information of the ship>>>"<<endl;
			cout<<"Ship Name : ";
			getline(cin,name);
	
			cout<<"Year Built: ";
			getline(cin,year);
			
			cout<<"The adress the ship was registered :"<<endl;
			cout<<"Registrar Office: ";
			getline(cin,regist);
		
			cout<<"Country : ";
			getline(cin,country);
		
			add = new Address(regist,country);
			s[i].read(name,year,add);
			i++;	
	}

	
	if(choice==2)		
	{
			cout<<"<<< Inventory of ships >>>"<<endl;
			cout<<"Total ship:"<<i<<endl;
			for(int n=0;n<i;n++)
			{
				s[n].print();
				cout<<endl;
			}	
	}
	

	
	cout<<endl;
	cout<<"Press any ket to continue..."<<endl;
	cout<<endl;

	}while(choice>=1 && choice<=2);


	return 0;
}

