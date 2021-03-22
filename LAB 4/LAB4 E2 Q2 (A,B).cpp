#include<iostream>

using namespace std;

class Rectangle
{
	int width,height;
	
	public:
	
	Rectangle()
	{
		width=0;
		height=0;
	}
	
	Rectangle(int a,int b)
	{
		width =a;
		height=b;
	}
	
	int calculateArea();
	
	friend Rectangle duplicate(Rectangle);
};

Rectangle::calculateArea()
{
	return width*height;
}

Rectangle duplicate(Rectangle a)
{
	a.calculateArea();
	return a;
}

int main()
{
	Rectangle rect(10,30),rectb;
	rectb=duplicate(rect);
	cout<<rectb.calculateArea()<<endl;
	system("pause"); 
}
