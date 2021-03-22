#include<iostream>

using namespace std;

class Length
{
	private:
		int len_inches;

	public:
		Length(int feet, int inches)
		{len_inches=12*feet+inches;}

		int getFeet(){return len_inches/12;}
		int getInches(){return len_inches%12;}
	
		friend bool operator<(Length ,Length );
		friend bool operator==(Length a, Length b);
	
};

bool operator==(Length a, Length b)
{
	return a.len_inches==b.len_inches;
}

bool operator<(Length a,Length b)
{
	return a.len_inches<b.len_inches;
}


int main()
{
	const int size = 4;
	int Fvalue, Ivalue;
	Length lens[size]= {Length(Fvalue,Ivalue),
						Length(Fvalue,Ivalue),
						Length(Fvalue,Ivalue),
						Length(Fvalue,Ivalue)};
	
	for(int i=0;i<size;i++)
	{
		cout<<"Enter the "<<i+1<<" feet value : ";
		cin>>Fvalue;
		cout<<"Enter the "<<i+1<<" inches value : ";
		cin>>Ivalue;
		Length objectholder(Fvalue,Ivalue);
		lens[i]=objectholder;
	}

	for(int i=0;i<size;i++)
	{
		if(lens[i]==lens[i+1])
		{	cout<<"Same length at indexes "<<i<<" and "<<i+1<<endl;		}
		if(lens[i]==lens[i+2])
		{	cout<<"Same length at indexes "<<i<<" and "<<i+2<<endl;		}
		if(lens[i]==lens[i+3])
		{	cout<<"Same length at indexes "<<i<<" and "<<i+3<<endl;		}
	}

	int i=0;
	
	if(lens[i]<lens[i+1])
	{
		if(lens[i]<lens[i+2])
		{
			if(lens[i]<lens[i+3])
			{
				cout<<" Shortest length in feet is "<<lens[i].getFeet()<<" feet at index "<<i<<endl;
			}else cout<<" Shortest length in feet is "<<lens[i+3].getFeet()<<" feet at index "<<i+3<<endl; 
		}else  cout<<" Shortest length in feet is "<<lens[i+2].getFeet()<<" feet at index "<<i+2<<endl;
	}else cout<<" Shortest length in feet is "<<lens[i+1].getFeet()<<" feet at index "<<i+1<<endl;
	
	
	if(lens[i]<lens[i+1])
	{
		if(lens[i+1]<lens[i+2])
		{
			if(lens[i+2]<lens[i+3])
			{
				cout<<" Longest length in feet is "<<lens[i+3].getFeet()<<" feet at index "<<i+3<<endl;
			}else cout<<" Longest length in feet is "<<lens[i+2].getFeet()<<" feet at index "<<i+2<<endl; 
		}else  cout<<" Longest length in feet is "<<lens[i+1].getFeet()<<" feet at index "<<i+1<<endl;
	}else cout<<" Longest length in feet is "<<lens[i].getFeet()<<" feet at index "<<i<<endl;
		
	 
	 
	
	
	
}
