//PT SEC03
//FINAL PROJECT - GROUP 14
//KHOO JIE XUAN A18CS0091
//PUTERA SYABIL A18CS0235
//PHARVEISH A/L SELVAM A18CS0233

#include<iostream>
#include<fstream>
#include<iomanip>
#include<chrono>
#include<ctime>

using namespace std;

const int numOfWard=10; 

class Driver
{
	private:
		string driver,ambulance;

	public:
		Driver(string n,string p)
		{	setName(n);
			setVehicle(p);	}
			
		void setName(string &name)
		{	driver=name;	}
	
		void setVehicle(string &plate)
		{	ambulance=plate;	}
	
		string getName()
		{	return driver;	}
	
		string getVehicle()
		{	return ambulance;	}
};

class Ambulance
{
	private:
		int i=0;
		Driver driver;
		string status;

	public:
		Ambulance(string name,string plateNum,string status)
			:driver(name,plateNum) 
		{	
			setStatus(status);
		}
	
		void setStatus(string &status)
		{	this->status=status;	}
	
		string getPlateNum()
		{	return driver.getVehicle();	}
	
		void dispatch()
		{	status="OUT";	}
	
		void back()
		{	status="IN";	}
	
		string getStatus()
		{	return status;	}
		
		string getName()
		{
			return driver.getName();
		}
	
		void print()
		{
			cout<<left;
			cout<<"\t\t\t\t\t\t"<<setw(50)<<driver.getName()
			<<setw(20)<<driver.getVehicle()	
			<<setw(20)<<status<<endl;
		}
};

class Info
{
	protected:
		string name,ic,gender,phone;
	public:
		Info(string name,string ic,string gender,string phone)
		{
			this->name=name;
			this->ic=ic;
			this->gender=gender;
			this->phone=phone;
		}
		
		virtual void print()
		{
			cout<<"\t\t\t\t\t\tName: "<<name<<endl;
			cout<<"\t\t\t\t\t\tI/C Number: "<<ic<<endl;
			cout<<"\t\t\t\t\t\tGender: "<<gender<<endl;
			cout<<"\t\t\t\t\t\tPhone number: "<<phone<<endl;
		}
		
		
};

class Staff : public Info
{
	private:
		string date,education, staffId;
	public: 
		Staff(string name,string ic,string gender,string phone,string date,string education,string staffId)
			:Info(name,ic,gender,phone)
		{
			this->date=date;
			this->education=education;
			this->staffId=staffId;
		}
		
		void printStaff()
		{
			Info::print();
			cout<<"\t\t\t\t\t\t"<<"Joined date: "<<date<<endl;
			cout<<"\t\t\t\t\t\t"<<"Education level: "<<education<<endl;
			cout<<"\t\t\t\t\t\t"<<"Staff ID: "<<staffId<<endl;	
		}	
};

class Nurse : public Staff
{
	private:
		string position;
	public:
		Nurse(string name,string ic,string gender,string phone,string address,string date,string education,string staffId, string position)
			:Staff(name,ic,gender,phone,date,education,staffId)
		{
			this->position=position;

		}
		
		void print()
		{
			cout<<"\t\t\t\t\t\tNurse"<<endl;
			Staff::print();
			cout<<"\t\t\t\t\t\t"<<"Position: "<<position<<endl;
		} 
	
};

class Receptionist : public Staff
{
	private:
		string counterNo;
	public:
		Receptionist(string name,string ic,string gender,string phone,string address,string date,string education,string staffId, string counterNo )
			:Staff(name,ic,gender,phone,date,education,staffId)
		{	this->counterNo=counterNo;	}
		
		void print()
		{
			cout<<"\t\t\t\t\t\tReceptionist"<<endl;
			Staff::print();
			cout<<"\t\t\t\t\t\t"<<"Counter: "<<counterNo<<endl; 
		}
};

class Doctor : public Staff
{
	private:
		string speciality,position,status;
	public:
		Doctor(string name,string ic,string gender,string phone,string address,string date,string education,string staffId, string position,string speciality,string status)
			:Staff(name,ic,gender,phone,date,education,staffId)
		{
			this->position=position;
			this->speciality=speciality; 
			this->status=status;
		}
		
		void print()
		{
			cout<<"\t\t\t\t\t\tDoctor"<<endl;
			Staff::print();
			cout<<"\t\t\t\t\t\t"<<"Position: "<<position<<endl;
			cout<<"\t\t\t\t\t\t"<<"Spciality: "<<speciality<<endl;
			cout<<"\t\t\t\t\t\t"<<"Status: "<<status<<endl;
		} 
		
};

class Ward
{
	private:
		string roomNo,floor,status;
	public:
		Ward(string room)
		{
			roomNo=room;
			status="EMPTY";
		}
		
		void setFloor()
		{	floor=roomNo.at(0);	}
		
		string getFloor()
		{	return floor;	}
		
		string getWardNumber()
		{	return roomNo;	}
		
		void setStatus()
		{	status="OCCUPIED";	}
		
		string getStatus()
		{	return status;	}
};

class Patient : public Info
{
	private:
		Ward *ward;
		string illness;
	public:
	 	Patient(string name,string ic,string gender,string phone,string illness)
	 		:Info(name,ic,gender,phone)	
		{
	 		this->illness=illness;	
	 		ward=NULL;
		}
		
		void setWard(Ward *w)
		{
			ward=w;
			ward->setFloor();
			ward->setStatus();	
		}
		
		string getName()
		{	return name;	}
		
		string getIc()
		{	return ic;	}
		
		string getGender()
		{	return gender;	}
		
		string getPhone()
		{	return phone;	}
		
		string getIllness()
		{	return illness;	}
		
		string getWard()
		{	return ward->getWardNumber();	}
		
		void leaveWard()
		{	ward=NULL;	}
		
		void print()
		{
			Info::print();
			cout<<"\t\t\t\t\t\tIllness: "<<illness<<endl;
			cout<<"\t\t\t\t\t\tWard: "<<ward->getWardNumber()<<" at floor of "<<ward->getFloor()<<endl;
			cout<<"\n\n";
		} 
			 
};



void choice1(const int &numOfAmbulance,Ambulance *car[],auto start )
{
	char answer;
	string plateNo;
	time_t end_time;
	
	cout<<left<<endl<<endl;
	cout<<"\t\t\t\t\t\tTotal Ambulance: "<<numOfAmbulance<<endl;
	cout<<"\t\t\t\t\t\t"<<setw(50)<<"DRIVER NAME"<<setw(20)<<"VEHIICLE"<<setw(20)<<"STATUS"<<endl;
	int flag=0,flag2=1;
	
	for(int i=0;i<numOfAmbulance;i++)
	{car[i]->print();car[i]->getPlateNum();}
	cout<<endl;
	
	cout<<"\t\t\t\t\t\t"<<"Is there any accident happened?(Y/N)"<<endl;
	cout<<"\t\t\t\t\t\t";
	cin>>answer;
	
	if(answer=='Y'||answer=='y')
	{	
	
		while(flag2){
		cout<<"\t\t\t\t\t\t"<<"Which ambulance you want to dispatch? \n\t\t\t\t\t\tPlease enter the plate number:";
		cin>>plateNo;
	
		for(int i=0;i<numOfAmbulance;i++)
		{
			if(plateNo==car[i]->getPlateNum() && car[i]->getStatus()=="IN")
			{
				flag=1;
				flag2=0;
				car[i]->dispatch();
				break;
			}	
		}
		
		if(flag)
		{		
			auto start = chrono::system_clock::now();
			time_t outTime = chrono::system_clock::to_time_t(start);
			cout<<"\t\t\t\t\t\tDispatch successfully"<<endl<<endl;
   			cout<<"\t\t\t\t\t\t\t"<<plateNo<<" 's dispatch time = "<<ctime(&outTime)<<"\n\n\n\n";
			break;
		} 
		else 
		{	
			cout<<"\t\t\t\t\t\tAmbulance not found or is being dispatched.Please enter again."<<endl;
		}
	}}
	else
	cout<<"\t\t\t\t\t\tGoing back to main menu."<<endl;
	cout<<"\t\t\t\t\t\t";
	system("pause");
}



void choice2(const int &numOfAmbulance,Ambulance *car[])
{
	char answer;
	string plateNo;
	int flag;
	cout<<"\t\t\t\t\t\t"<<"Are you a driver ?(Y/N)"<<endl;
	cout<<"\t\t\t\t\t\t";
	cin>>answer;
	if(answer=='Y'||answer=='y')
	{
		cout<<"\t\t\t\t\t\t"<<"Are you coming back? (Y/N)"<<endl;
		cout<<"\t\t\t\t\t\t";
		cin>>answer;
			if(answer=='Y'||answer=='y')
			{
				cout<<"\t\t\t\t\t\tAmbulance being dispatched out: ";
				for(int i=0;i<numOfAmbulance;i++)
				{
					if(car[i]->getStatus()=="OUT")
					cout<<car[i]->getPlateNum()<<"\t";
					
				}
				
			
		cout<<"\n\t\t\t\t\t\t"<<"Which is your car plate?"<<endl;
		cout<<"\t\t\t\t\t\t";
		cin>>plateNo;
			for(int i=0;i<numOfAmbulance;i++)
			{
				if(car[i]->getPlateNum()==plateNo)
				{	car[i]->back();
					flag=0;break; }
				else 
				flag=1;
			}
				if(flag)cout<<"Record not found.Please try again."<<endl;
			}
	
		else
		{
			cout<<"\t\t\t\t\t\t"<<"If you wish to view the record of ambulance.Please return to the main menu."	<<endl;
		}
	}
	else
	{
		cout<<"\t\t\t\t\t\t"<<"Only driver can access to this function. "
		<<"If you wish to view the record of ambulance.Please return to the main menu."	<<endl;
	}
	
	fstream out;
	out.open("ambulance.txt",ios::out);
	out<<numOfAmbulance;
	out<<endl;
	for(int i=0;i<numOfAmbulance;i++)
	{
		out<<car[i]->getName()<<" ";
		out<<car[i]->getPlateNum()<<" ";
		out<<car[i]->getStatus()<<endl;
	}
	
	cout<<"\t\t\t\t\t\t";
	system("pause");
}


void choice3(int &numOfPatient,Patient *patient[])
{
	for(int i=0;i<numOfPatient;i++)
	{
		patient[i]->print();
	}
	
	cout<<"\t\t\t\t\t\t";
	system("pause");
	
}

int choice4(int &numOfPatient,Patient *patient[], Ward ward[])
{
	int choice,index;
	string name, ic,gender,phone,illness,wardNo;

	cin.ignore();
	cout<<"\t\t\t\t\t\tName: ";
	getline(cin,name,'\n');
		
	cout<<"\t\t\t\t\t\tIc Number: ";
	cin>>ic;
		
	cout<<"\t\t\t\t\t\tGender: ";
	cin>>gender;
	cin.ignore();
	cout<<"\t\t\t\t\t\tPhone Number: ";
	cin>>phone;
	cin.ignore();
	cout<<"\t\t\t\t\t\tAvailable ward :";
	for(int i=0;i<numOfWard;i++)
	{
		if(ward[i].getStatus()=="EMPTY")
		cout<<"\t"<<ward[i].getWardNumber(); 
	 } 
	cout<<"\n\t\t\t\t\t\tWard No: ";
	cin>>wardNo;
	cin.ignore();
	cout<<"\t\t\t\t\t\tIllness: ";
	getline(cin,illness);
	
	patient[numOfPatient]=new Patient{name,ic,gender,phone,illness};
	
	for(int i=0;i<numOfWard;i++)
	{
		if(wardNo==ward[i].getWardNumber()&&ward[i].getStatus()=="EMPTY")
		index=i;
	}

	patient[numOfPatient]->setWard(&ward[index]);
	numOfPatient=numOfPatient+1;
		
	
	cout<<"\t\t\t\t\t\t";

	fstream out;
	out.open("patient.txt",ios::out);
	out<<numOfPatient;
	out<<endl;
	for(int i=0;i<numOfPatient;i++)
	{
		out<<patient[i]->getName()<<"	";
		out<<patient[i]->getIc()<<" ";
		out<<patient[i]->getGender()<<" ";
		out<<patient[i]->getPhone()<<" ";
		out<<patient[i]->getWard()<<" ";
		out<<patient[i]->getIllness()<<endl;
	}
	
	system("pause");
	return numOfPatient;

}

void choice5(int &numOfStaff,Staff *staff[])
{
	cout<<"\n\n";
	cout<<"\t\t\t\t\t\tTotal number of staff = "<<numOfStaff<<endl;
	for(int i=0;i<numOfStaff;i++)
	{
		cout<<"\t\t\t\t\t\tStaff# "<<i+1<<endl;
		staff[i]->print();
		cout<<endl;
	}
	
	cout<<"\t\t\t\t\t\t";
	system("pause");
}





int main()
{
	int i= 0,choice=0,j=0,y=0;
	int numOfAmbulance,numOfPatient,index,numOfStaff;
	string name,ambulancePlate,status;
	
	string ic,gender,phone,illness,wardNo;
	
	fstream read;
	read.open("ambulance.txt",ios::in);
		if(read.fail())
		cout<<"No record found."<<endl;
	
	read>>numOfAmbulance;
	Ambulance *car[numOfAmbulance];
	
	do{
		read>>name;
		read>>ambulancePlate; 
		read>>status;
		car[i]= new Ambulance{name,ambulancePlate,status};
		++i;
	}while(!read.eof());
	
	read.close();
	
	
	read.open("patient.txt",ios::in);
		if(read.fail())
		cout<<"No record found."<<endl;
	read>>numOfPatient;
	read.ignore();
	Patient *patient[numOfPatient];
	Ward ward[numOfWard]={ Ward("1-10"),Ward("1-11"),Ward("1-12"),Ward("1-13"),Ward("1-14"),
					Ward("2-10"),Ward("2-11"),Ward("2-12"),Ward("2-13"),Ward("2-14"),
				  };
				  
	do{
		getline(read,name,'\t');
		read>>ic>>gender>>phone>>wardNo;
		read.ignore(); 
		getline(read,illness);
		patient[j]=new Patient{name,ic,gender,phone,illness};
	
		for(int i=0;i<10;i++)
		{
			if(wardNo==ward[i].getWardNumber())
			index=i;
		}
		patient[j]->setWard(&ward[index]);
		++j;
	}while(!read.eof());
	
	read.close();
	
	string position,address,date,education,staffId,speciality,counterNo;
	
	
	
	read.open("staff.txt",ios::in);
		if(read.fail())
		cout<<"No record found."<<endl;
		
	read>>numOfStaff;
	Staff *staff[numOfStaff];
	Doctor *doctor[numOfStaff];
	Receptionist *receptionist[numOfStaff];
	Nurse *nurse[numOfStaff];
	
	do{
	read>>position;
	if(position=="Doctor")
		{
			getline(read,name,'\t');
			read>>ic>>gender>>phone;
			getline(read,address,'\t');
			read>>date>>education>>staffId>>speciality>>position;
			getline(read,status);
			doctor[y]=new Doctor{name,ic,gender,phone,address,date,education,staffId,position,speciality,status};
			staff[y]=doctor[y];
			y++;
		}
	else if(position=="Nurse")
		{
			getline(read,name,'\t');
			read>>ic>>gender>>phone;
			getline(read,address,'\t');
			read>>date>>education>>staffId>>position;
			nurse[y]=new Nurse{name,ic,gender,phone,address,date,education,staffId,position};
			staff[y]=nurse[y];
			y++;
		}
		
	else
		{
			getline(read,name,'\t');
			read>>ic>>gender>>phone;
			getline(read,address,'\t');
			read>>date>>education>>staffId>>counterNo;
			receptionist[y]=new Receptionist{name,ic,gender,phone,address,date,education,staffId,counterNo };
			staff[y]=receptionist[y];
			y++;
		}
	
	}while(y<numOfStaff);
	
	auto start = chrono::system_clock::now();
	time_t time = chrono::system_clock::to_time_t(start);
	cout<<right;

	while(choice!=6){
	system("cls");
	cout<<"\n\n\n\n\n\n"<<"\t\t\t\t\t\t\t\tHello! Welcome to emergency department!"<<endl;
	cout<<"\t\t\t\t\t\t\t   Your logged in time is "<< ctime(&time);
	cout<<"\n\n\t\t\t\t\t\t\t\t"<<"Hospital Emergency Department \n\n";	
	cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
	cout<<"\t\t\t\t\t\t|                                           	                  |\n";
	cout<<"\t\t\t\t\t\t|             1  -> Check & Dispatch Ambulance                    |\n";
	cout<<"\t\t\t\t\t\t|             2  -> Record for Ambulance Operation                |\n";
	cout<<"\t\t\t\t\t\t|             3  -> View Patient Information                      |\n";
	cout<<"\t\t\t\t\t\t|             4  -> Add Patient                                   |\n";
	cout<<"\t\t\t\t\t\t|             5  -> View Staff Information                        |\n";	
	cout<<"\t\t\t\t\t\t|             6  -> Exit the program                              |\n";	
	cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
    
    
	cout<<"\n\n\t\t\t\t\t\t"<<"Please enter the number and proceed to the function  \n\n";
	cout<<"\t\t\t\t\t\tEnter your choice: ";
	cin>>choice;
	while(choice<1 || choice>6)
	{
	cout<<"\t\t\t\t\t\t"<<"Enter your choice again: ";
	cin>>choice;
	}
	
	switch(choice)
	{
		case 1:	
			choice1(numOfAmbulance,car,start);
			break;
	
		case 2: 
			choice2(numOfAmbulance,car);
			break;
		case 3:
			choice3(numOfPatient,patient);
			break;
		case 4:
			numOfPatient=choice4(numOfPatient,patient,ward);
			break;
		case 5:
			choice5(numOfStaff,staff);
			break;
		case 6:
			cout<<"\t\t\t\t\t\t"<<"Thank you for using this system !"<<endl;
			break;
	}
	
	}

	

	
	

	
}

