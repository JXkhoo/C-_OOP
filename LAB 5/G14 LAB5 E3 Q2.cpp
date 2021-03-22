#include<iostream>
#include<string>

using namespace std;

int main()
{
	
	string str1;
	str1.assign("Programming is a subject!");
	cout<<str1<<endl;
	str1.insert(17,"good ");
	cout<<str1<<endl;
	
	string str2="re";
	str1.replace(12,13,str2);
	cout<<str1<<endl;	
}
	 
