#include<iostream>
#include<string>

using namespace std;

string phoneFormat(string& n)
{
	n.insert(0,"+");
	n.insert(4,"-");
	n.insert(9,"-");
	return n;
}

int main()
{
	string number,newstr;
	cout<<"Enter your handphone no. ->";
	getline(cin,number);
	newstr = phoneFormat(number);
	cout<<"Your formatted handphone no. ->"<<newstr;
} 
