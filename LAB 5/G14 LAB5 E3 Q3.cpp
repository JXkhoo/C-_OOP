#include<iostream>
#include<string>


using namespace std;

int main()
{
	
	string student[]={"Muhamad Husin, A123456",
						"Nor Asma, A156782",
						"Raja Kumar, A187623",
						"Muhamad Ali, A123908",
						"Ali Shah, A145234",
						"Nor Nadia, A128734",
						"Siti Sarah, A120945",
						"Siti Kahadijah, A154237",
						"Syed Azman, A276456",
						"Chong Wei, A156278"};

	string fullName[10]; 
	string matrix[10];
	int dot;					
	for(int i=0;i<10;i++)
	{
		dot = student[i].find(",");
		matrix[i]=student[i].substr(dot);
		fullName[i].assign(student[i],0,dot);
	}
	
	string firstName[10];
	int space;
	for(int i=0;i<10;i++)
	{
		space = student[i].find(" ",0);
		firstName[i].assign(student[i],0,space);
	}
	
	string name;
	
	cout<<"Searching Student's Info"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Enter the name or partial name,\n"
		<<"you would like to search for: ";
		
	getline(cin,name);

	cout<<"Search results: \n";
	if(name.find(" ")== name.npos)
	{
		for(int i=0;i<10;i++)
		{
			if(name==firstName[i])
			{
				cout<<fullName[i]<<matrix[i]<<endl;
			}
		}
	}
	else
	
		for(int i=0;i<10;i++)
		{
			if(name==fullName[i])
			{
				cout<<fullName[i]<<matrix[i]<<endl;
			}
		}
	return 0;	
}
	 
