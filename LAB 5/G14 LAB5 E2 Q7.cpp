#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str1="Hello",str2="World",str3;
	int len;
	
	str3.assign(str1);
	cout<<"str3 : "<<str3<<endl;
	
	str3.append(str2);
	cout<<"New str3 : "<<str3<<endl;
	
	len=str3.length();
	cout<<"The new length of str3: "<<len<<endl;
	
	str2=str3.substr(0,5);
	cout<<"First half of the str3: "<<str2<<endl;
	
	return 0;
}
