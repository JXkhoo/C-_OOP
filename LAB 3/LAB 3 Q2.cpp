#include<fstream>
#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Product 
{
     private :
          int code,quan;
          double price;
          
     public :
		  
		  Product() 
		  {
		  	code=0;
		  	price=0;
		  	quan=0;
		  }
		  Product(int other_code,double other_price,int q)
		  {
		  	code=other_code;
		  	price=other_price;
		  	q=quan;
		  };
         
         
         void setCode(const int product_code)
		 {
		 	code=product_code;
		 };
         void setPrice(const double product_price)
		 {
		 	price=product_price;
		 };
		 void setQty(const int q)
		 {
		 	quan=q;
		 };
         int getCode()const
		 {
		 	return code;
		 };
         double getPrice()const
		 {
		 	return price;
		 };
		 
		 int getQty()const
		 {
		 	return quan;	
		 };
         
         
}; 

int main()
{
	int numofproduct=100;
	int product_code,product_qty;
	double product_price;
	Product goods[numofproduct];
	
	cout<<"How many products you want to enter =>   ";
	cin>>numofproduct;
	
	
	
	for(int i=0;i<numofproduct;i++)
	{
		cout<<"Enter product  #"<<i+1<<endl;
		
		cout<<"Code => ";
		cin>>product_code;
		goods[i].setCode(product_code);
		
		cout<<"Price => ";
		cin>>product_price;
		goods[i].setPrice(product_price);
		
		cout<<"Quantity => ";
		cin>>product_qty;
		goods[i].setQty(product_qty);
		
	}
	
	
	cout<<endl;
	cout<<right;
	cout<<"Data Entry Summary\n";
	
	cout<<"No"<<setw(15)<<"Product Code"<<setw(15)<<"Price"<<setw(15)<<"Quantity"<<setw(15)<<"Total"<<endl;
	
	for(int i=0;i<numofproduct;i++)
	{
		cout<<(i+1)<<setw(15)<<goods[i].getCode()<<setw(15)<<fixed<<setprecision(2)<<goods[i].getPrice()
		<<setw(15)<<goods[i].getQty()<<setw(15) << goods[i].getPrice()*goods[i].getQty()<<endl;
	}
	
	fstream out("data.dat",ios::out|ios::binary);
	
	double p[numofproduct];
	int c[numofproduct];
	int q[numofproduct];
	
	for(int i=0;i<numofproduct;i++)
	{

		p[i]=goods[i].getCode();
	
		c[i]=goods[i].getPrice();
		
		q[i]=goods[i].getQty();
		
	}
	
	
	for(int i=0;i<numofproduct;i++)
	{
		out.write(reinterpret_cast<char*>(&p[i]),sizeof(p[i])); 
		out.write(reinterpret_cast<char*>(&c[i]),sizeof(c[i]));
		out.write(reinterpret_cast<char*>(&q[i]),sizeof(q[i]));
	}
	

}
