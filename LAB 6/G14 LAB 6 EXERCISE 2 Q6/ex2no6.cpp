//Program 6.6
#include <iostream>
#include <fstream>
using namespace std;

struct catalog
{
	char title [50];
	char author[50];
	char publisher[30];
	int yearpublish;
	double price;
};

int main() {
	catalog book;
	
	
	fstream fbook("book.dat", ios::in|ios::binary); //open and write
	
	if (!fbook)
	{
		cout<<"Error opening file";
		return 0;
	}
	
	cout<<"These are the book information in the file:\n";
	fbook.read(reinterpret_cast<char*>(&book),sizeof(book));
	
	
	while(!fbook.eof())
	{
		//Display the recordabout the book
		cout<<"Title: "<<book.title<<endl;
		cout<<"Author: "<<book.author<<endl;
		cout<<"Publisher name: "<<book.publisher<<endl;
		cout<<"Year publish: "<<book.yearpublish<<endl;
		cout<<"Price: "<<book.price<<endl<<endl;
		
		//read the contents to the binary file
		fbook.read(reinterpret_cast<char*>(&book),sizeof(book));
	}
	
	fbook.close();
	return 0;
	
}
