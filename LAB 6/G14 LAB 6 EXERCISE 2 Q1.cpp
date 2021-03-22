#include <iostream>
#include <fstream>
using namespace std;







int main()
{
	fstream inout;
	inout.open("city.txt",ios::in);
	if(inout.fail())
	{
		cout<<"file does not exist ";
		return 0;
		
	}
	
	char city[50];
	while(!inout.eof())
	{
		inout.getline(city,50);
		cout<<city<<endl;
		
		
	}
	inout.close();
	cout<<"done"<<endl;
	
	cout<<"Write a new city"<<endl;
	
	
	int f=1;
	
	do
	{
	
	cin.getline(city,50);
	ofstream addData("city.txt",ios::app);
	addData.seekp(0,ios::beg);
	addData<<endl<<city<<endl;
	
	cout<<"Do you wan to add more? (1=yes)";
	
	cin>>f;
	cin.ignore();
	if(f!=1)
	return 0;
	
	
	}while(f=1);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
