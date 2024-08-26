/*
OOP Assignment-3

Name: Purva Gorakh Phadol
SE Computer
Div: B
Roll No: 49
Date: 24/09/22

Que. Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.
*/

#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;

class publication
{
	public:
	string title;
	float price;
	virtual void get_data()=0;
	virtual void display_data()=0;
};

class book: virtual public publication
{
	public:
	int page ;
	void get_data()
	{
		cout<<"ENTER THE TITLE OF BOOK: ";
		cin>>title;

		enter:
		try
		{
			cout<<"ENTER THE PRICE OF BOOK: ";
			cin>>price;
			if (price > 1000)
			{
				throw 1;
			}
		}
		catch (int i)
		{
			cout<<"Too Expensive! Please Enter Small Amount"<<endl;
			goto enter;
		}
		
		cout<<"ENTER THE PAGE COUNT OF BOOK: ";
		cin>>page;
	}

	void display_data()
	{
		cout<<"TITLE OF BOOK: "<<title<<endl;
		cout<<"PRICE OF BOOK: "<<price<<endl;
		cout<<"PAGES OF BOOK: "<<page<<endl;
	}
};

class tape: virtual public publication
{
	public:
	int time;
	void get_data()
	{
		cout<<"ENTER THE TITLE OF TAPE: ";
		cin>>title;
		
		enter1:
		try
		{
			
			cout<<"ENTER THE PRICE OF TAPE: ";
			cin>>price;
			if (price > 1000)
			{
				throw (price);
			}
		}
		catch (float)
		{
			cout<<"Too Expensive! Please Enter Small Amount "<<endl;
			goto enter1;
		}
		enter2:
		try
		{
			cout<<"ENTER THE PLAY TIME OF TAPE: ";
			cin>>time;
			if (time > 100)
			{
				throw (time);
			}
		}
		catch (int)
		{
			cout<<"Playtime too long! Shorten the Playtime "<<endl;
			goto enter2;
		}
	}
	void display_data()
	{
		cout<<"TITLE OF TAPE: "<<title<<endl;
		cout<<"PRICE OF TAPE "<<price<<endl;
		cout<<"PLAY TIME OF TAPE: "<<time<<endl;
	}
};

int main()
{
	publication *p[50];
	book b;
	tape t;
	int i=0,n,ch;
	char choice;
	cout << "\n****** Main Menu ******\n";
	do
	{
		cout<<"1. Book \n2. Audio Tape \n3. Display Records \n4. Exit";
		cout<<"\nEnter Your Choice: ";
		cin>>ch;
		cout<<"\n";
		switch(ch)
		{
			case 1:
				p[i]=&b;
				p[i]->get_data();
				i++;
				break;
			case 2:
				p[i]=&t;
				p[i]->get_data();
				i++;
				break;
			case 3:
				n=i;
				for (i=0;i<n;i++)
				{
					p[i]->display_data();
					cout<<"-----------------------------------------\n";
				}
				break;
			case 4:
				cout<<"Exit";
		}
		cout<<"\nDo you want to continue?? (Y/N) "<<endl;
		cin>>choice;
	}
	while (choice=='Y');
	return 0;
}

/*
Output

****** Main Menu ******
1. Book
2. Audio Tape
3. Display Records
4. Exit
Enter Your Choice: 1

ENTER THE TITLE OF BOOK: FDS
ENTER THE PRICE OF BOOK: 1200
Too Expensive! Please Enter Small Amount
ENTER THE PRICE OF BOOK: 830
ENTER THE PAGE COUNT OF BOOK: 230


Do you want to continue?? (Y/N)
Y
1. Book
2. Audio Tape
3. Display Records
4. Exit
Enter Your Choice: 2

ENTER THE TITLE OF TAPE: audio
ENTER THE PRICE OF TAPE: 1110 
Too Expensive! Please Enter Small Amount
ENTER THE PRICE OF TAPE: 650
ENTER THE PLAY TIME OF TAPE: 23


Do you want to continue?? (Y/N)
Y
1. Book
2. Audio Tape
3. Display Records
4. Exit
Enter Your Choice: 3

TITLE OF BOOK: FDS
PRICE OF BOOK: 830
PAGES OF BOOK: 230
-----------------------------------------
TITLE OF TAPE: audio
PRICE OF TAPE 650
PLAY TIME OF TAPE: 23
-----------------------------------------

Do you want to continue?? (Y/N)
N

*/
