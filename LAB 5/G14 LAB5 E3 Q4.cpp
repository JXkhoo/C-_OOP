#include<iostream>
#include<string>
#include<cstring>


using namespace std;

int main()
{
	string name,title;
	int year;
	string lastName;
	string firstName; 
	
	cout<<"Enter author of the book -> ";
	getline(cin,name);
	
	int space=name.find(" ",0);
	firstName.assign(name,0,space);
		
	int i= name.find(" ",0)+1;
	
	lastName = name.substr(i);
	
	cout<<"Enter year of published -> ";
	cin>>year;

	cout<<"Enter a book title -> ";
	cin.ignore();
	getline(cin,title);
	
	cout<<endl;
	cout<<"The Formatted Book Reference :"<<endl;
	cout<<lastName<<","<<firstName<<" ("<<year<<") "<<title;
	
} 
