#include<iostream>
#include<string>
#include<fstream>
#include<iomanip> 

using namespace std;

class Product
{
	private:
		string n;
		double p;
		int q;
	public:
		Product()
		{
			p=0;
			q=0;	
		};
		
		Product(string name,double price,int qty)
		{
			n=name;
			p=price;
			q=qty;
		}
		
		void display()
		 {
		 	cout<<n;
		 	cout<<p;
		 	cout<<q;
		 } 
		
	
}; 

void AddItem(fstream &out,string n,double p,int q)
{
	out.write(reinterpret_cast<char*>(&n),sizeof(n));
	out.write(reinterpret_cast<char*>(&p),sizeof(p));
	out.write(reinterpret_cast<char*>(&q),sizeof(q));
} 

void DisplayItem()
{
	Product first;
	ifstream out; 
	out.open("report.dat", ios::binary);
	while(out.read((char*)&first,sizeof(first))) 
	{
		first.display();
	}
}


int main()
{
	
	string name;
	double price;
	int option,qty;
	
	fstream outFile("report.dat",ios::out|ios::ate|ios::binary);
		
	if(outFile.fail())cout<<"Failed to create file.";
	
	cout<<"1. Add new item in the product file\n";
	cout<<"2. Display all item\n";
	cout<<"3. Exit\n";
	cout<<"Select option:";
	
	cin>>option;
	cin.ignore();
	
	if(option==1)
	{
				
		cout<<"Item name:";
		getline(cin,name);
		
		cout<<"Price per item: RM";
		cin>>price; 

		cout<<"Quantity:";
		cin>>qty; 
		
		Product first(name,price,qty);
		AddItem(outFile,name,price,qty);
	}
	
	else if(option==2)
	{
		DisplayItem();
	}
	
	else if(option==3)
	{
		exit(1);
	}
	
	else
	cout<<"Invalid Input!!!"<<endl;
}
