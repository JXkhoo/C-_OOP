#include<iostream>

using namespace std;

class Square;

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
	
	void convert (Square);
};

class Square
{
	private:
		int side;
	public:
		Square(int side)
		{
			this->side=side;
		}
		friend class Rectangle;
};

void Rectangle::convert(Square a)
{
	width=a.side;
	height=a.side;
} 

Rectangle::calculateArea()
{
	return width*height;
}

int main()
{
	Square box(10);
	Rectangle rect;
	rect.convert(box) ;
	cout<<"The area of the reactangle is: "<<rect.calculateArea()<<endl;
	system("pause"); 
}

