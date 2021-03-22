#include <iostream>
#include <fstream>
using namespace std;

struct catalog
{
	char title[50];
	char author[50];
	char publisher[30];
	int yearpublish;
	double price;
	
};


int main()
{
	catalog book;
	char again;
	fstream fbook;
	fbook.open("book.dat",ios::out|ios::binary);
	do
	{
		cout<<"enter the following data about a book : \n";
		cout<<"Tille: ";
		cin.getline(book.title,50);
		cout<<"Author: ";
		cin.getline(book.author,50);
		cout<<"Publisher name:";
		cin.getline(book.publisher,30);
		cout<<"year publish ";
		cin>>book.yearpublish;
		cin.ignore();
		cout<<"price: ";
		cin>>book.price;
		cin.ignore();

		fbook.write((char *)&book,sizeof(catalog) );
		
		cout<<"Do you want to enter another record? (Y/N)";
		cin>>again;
		cin.ignore();
		
		


		
	}while(again=='Y'||again=='y');
	
	
	fbook.close();
	
}
