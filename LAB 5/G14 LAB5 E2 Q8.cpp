#include<iostream>
#include<string>

using namespace std;
int main()
{
	string firstname="Abu",lastname="Bakar";
	string fullname;
	fullname=firstname+" "+lastname;
	fullname.append(",");
	fullname.append("Dr");
	cout<<fullname<<endl;
	fullname.replace(10,2,"Prof Madya");
	cout<<fullname<<endl;
	fullname.erase(15,21);
	cout<<fullname<<endl;
	fullname.insert(10,"Associate ");
	cout<<fullname<<endl;	
} 
