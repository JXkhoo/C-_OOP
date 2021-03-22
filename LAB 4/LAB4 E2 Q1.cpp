#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

class kawan2;

class kawan1
{
	int value;
	char girlF[10];
	int age;
	void secret(){strcpy(girlF,"Amy");age=30;}
	
	public:
	kawan1(int a){value=a;secret();}
	void print(){cout<<""<<value<<"";}
	void gossip(kawan2);
	friend class kawan2;
	
};

class kawan2 
{
	int value;
	char girlF[10];
	int age;
	void secret(){strcpy(girlF,"Lisa");age=22;}
	
	public:
	kawan2(int a){value=a;secret();}
	void print(){cout<<""<<value<<"";}
	void gossip(kawan1);
	friend void kawan1::gossip(kawan2);
	
};

void kawan1::gossip(kawan2 c)
{
	cout<<value<<" gossips on "<<c.value<<endl;
	cout<<value<<" says "<<c.value<<" girl friend is "<<c.girlF<<endl;
}

void kawan2::gossip(kawan1 b)
{
	cout<<value<<" gossips on "<<b.value<<endl;
	cout<<value<<" says "<<b.value<<" age is "<<b.age<<endl;
}



int main()
{
	kawan1 objek1(100);
	kawan2 objek2(50);
	objek1.gossip(objek2);
	objek2.gossip(objek1);
	
	return 0;
}


