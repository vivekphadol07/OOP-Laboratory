/*
OOP Assignment-1

Name: Vivek Gorakh Phadol
SE Computer
Batch: B
Roll No: 66
Date: 

Que. Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling. */

#include<iostream>
#include<string.h>
using namespace std;

class student
{
	public:
	int srno;
	char name[30];
	int rollno;
	char cls[5];
	char div[5];
	char dob[15];
	char bldgrp[7];
	char add[50];
	long long int mobno;
	char dlno[25];
	static int count;
	void get_data();
	friend void display_data(student & obj);

	student()      //constructor
	{
		rollno=0;
		cout<<"\t Constructor";
		rollno=count;
		count++;
	}

	~student()  //destructor
	{
		cout<<"\nDestructor"<<endl;
		cout<<"Destroying the object"<<endl;
		count++;
	}

	static void getcount()  //static member function
	{
		cout<<"\n Count"<<count;
	}

	student (int rollno)
	{
		this-> rollno=rollno;
	}

	student (student & obj) //copy constructor
	{
		strcpy(name,obj.name);
		rollno=obj.rollno;
		strcpy(cls,obj.cls);
		strcpy(div,obj.div);
		strcpy(dob,obj.dob);
		strcpy(bldgrp,obj.bldgrp);
		strcpy(add,obj.add);
		mobno=obj.mobno;
		strcpy(dlno,obj.dlno);
		srno=count;
		count++;
	}
};	//end of class

int student::count=0;

void student::get_data()
{
	cout<<"\nEnter Roll No:";
	cin>>rollno;
    cout<<"\nEnter Student Name:";
	cin.ignore();
	cin.getline(name,30);
	cout<<"\nEnter Class:";
	cin>>cls;
	cout<<"\nEnter Division:";
	cin>>div;
	cout<<"\nEnter Date of Birth:";
	cin>>dob;
	cout<<"\nEnter Blood Group:";
	cin>>bldgrp;
	cout<<"\nEnter Address:";
	cin.ignore();
	cin.getline(add,50);
	cout<<"\nEnter Mobile No:";
	cin>>mobno;
	cout<<"\nEnter Driving License No:";
	cin>>dlno;
}

void display_data(student & obj)
{
    cout<<"\n"<<obj.rollno;
	cout<<"\t"<<obj.name;
	cout<<"\t"<<obj.cls;
	cout<<"\t"<<obj.div;
	cout<<"\t"<<obj.dob;
	cout<<"\t"<<obj.bldgrp;
	cout<<"\t"<<obj.add;
	cout<<"\t"<<obj.mobno;
	cout<<"\t"<<obj.dlno;
}

int main()
{
	student s1;
	student s2(s1);   //copy constructor called
	cout<<"\nEnter data for 1st student:"<<"\n";
	s1.get_data();
	
	cout<<"All the details are given below:";
	cout<<"\nRoll No.\tName\t\tClass\tDiv\tDOB\tBlood Group\tAddress\t\tMobile No.\tDL No.\n";
	display_data(s1);
	
	student *s[50];  //array of objects i.e students
	int i,n;
	cout<<"\n\nHow many student objects you want to create ?? ";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		s[i]=new student();
	}
	
	for(i=0;i<n;i++)
	{
		cout<<"Enter Data of Student "<<i+1<<endl;
		s[i]->get_data();
	}
	cout<<"\nAll the details are given below:"<<endl;
	cout<<"\nRoll No.\tName\t\tClass\tDiv\tDOB\tBlood Group\tAddress\t\tMobile No.\tDL No.\n";
	for(i=0;i<n;i++)
	{
		display_data(*s[i]);
	}
	
	for(i=0;i<n;i++)
	{
		delete (s[i]);
	}
	return 0;
}

/*
Output
         Constructor
Enter data for 1st student:

Enter Roll No:1

Enter Student Name:Vivek Phadol

Enter Class:SE

Enter Division:B

Enter Date of Birth:30-10-2003

Enter Blood Group:A+ve

Enter Address:Yashwantnagar Nashik

Enter Mobile No:8080789718

Enter Driving License No:MH221234566
All the details are given below:
Roll No.        Name            Class   Div     DOB       Blood Group     Address		        Mobile No.      DL No.

1               Purva Phadol    SE      B       30-10-2003      A+ve    Yashwantnagar Nashik    8080789718      MH221234566


How many student objects you want to create ?? 2
         Constructor     Constructor
Enter Data of Student 1

Enter Roll No:2

Enter Student Name:Vedant Patil

Enter Class:SE

Enter Division:B

Enter Date of Birth:7-04-2003

Enter Blood Group:B+ve

Enter Address:Ravet Jalgoan

Enter Mobile No:9878987898

Enter Driving License No:MH2022123456 

Enter Data of Student 2

Enter Roll No:3

Enter Student Name:Jayesh Patil

Enter Class:SE

Enter Division:B

Enter Date of Birth:11-11-2003

Enter Blood Group:AB+ve

Enter Address:Khutwad Nagar

Enter Mobile No:9856746764

Enter Driving License No:MH201923456

All the details are given below:

Roll No.        Name            Class   Div     DOB     Blood Group     Address         Mobile No.      DL No.

2               Vedant Patil    SE      B       7-04-2003       B+ve    Ravet Jalgoan   9878987898      MH2022123456
3               Jayesh Patil    SE      B       11-11-2003      AB+ve   Khutwad Nagar   9856746764      MH201923456
Destructor
Destroying the object

Destructor
Destroying the object

Destructor
Destroying the object

Destructor
Destroying the object
*/
