#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<conio.h>
int main();
using namespace std;
ostream& col(ostream &a)//user defined manupulator to display the details in column
{
	a<<setw(15);
	return a;
}
class exam
{
	protected:
		int efm1;//to store the full marks of the 1st terminal
		int efm2;//to store the full marks of the final terminal
		int em1;//to store the marks in 1st terminal
		int em2;//to store the marks in final terminal
	public:
		exam()//default constructor for the exam class
		{
			efm1=0;
			efm2=0;
			em1=0;
			em2=0;
		}
};
class tutorial
{
	protected:
		int tntut;//to store the total no of tutorial given
		int ntut;//to store the total no of tutorial submitted by the student
	public:
		tutorial()//constructor of the tutorial class
		{
			ntut=0;
			tntut=0;
			
		}
};
class classroom:public tutorial,public exam
{
	private:
		int cDays;//to store the total no of the college days
		int pDays;//to store the total no of the present days
		char name[20];//to store the name of the student
		float imark;//to store the internalmarks of the student
		int roll;//to store the rollno of the student
	public:
		void intialize()//to store the name and roll no of the student for the first time only
		{
			cout<<"name:";
			cin.sync();
			cin.getline(name,20);
			cout<<"roll no:";
			cin>>roll;
		}
		
		void display()//to display the name,roll,no of present days of student and do attendance
		{
			cDays+=1;
			cout<<roll<<ends<<name<<ends<<pDays<<"->"<<ends;
			cin>>pDays;
		}
		classroom()
		{
			cDays=0;
			pDays=0;
			imark=0;
		}
		void increaseTut()//function to increase the total no of tutorial submitted by the student
		{
			tntut+=1;//to count the total no of tutorial
			cout<<roll<<ends<<name<<ends<<ntut<<cout<<"->"<<ends;
			cin>>ntut;
		}
		void increaseMark1(int m)//to store the exam marks of the 1st terminal exam
		{
			efm1=m;
			cout<<roll<<ends<<name<<ends;
			cout<<"marks:";
			cin>>em1;
			
		}
		void increaseMark2(int m)//to store the internal marks of the final terminal
		{
			efm2=m;
			cout<<roll<<ends<<name<<ends;
			cout<<"marks:";
			cin>>em2;
		}
		void displayAll()//to display the details of all the sudent in the table format
		{

			cout<<col<<name<<col<<roll<<col<<pDays<<col<<em1<<col<<em2<<col<<ntut<<col<<imark<<endl;
		}
		
			void increaseInternal(float x)
			{
				imark=x;
			}
			float getntut()
			{
				return (float)ntut;
			}
			int gettntut()
			{
				return tntut;
			}
			float getpDays()
			{
				return (float)pDays;
			}
			int getcDays()
			{
				return cDays;
			}
			float getem1()
			{
				return (float)em1;
			}
			float getem2()
			{
				return (float)em2;
			}
			int getefm1()
			{
				return efm1;
			}
			int getefm2()
			{
				return efm2;
			}
			
		void printInternal()//to print the internal marks of all the student in the table format
		{
			cout<<col<<name<<col<<imark<<endl;
			
		}
	
};
class admin
{
	private:
		char adminName[20];//to store the admin name
		char pass[10];//to store the password
		int check;//to check whether acount is created or not
	public:
		void input()//to get the admin name and password for every time
		{
			cout<<"admin name:";
			cin.getline(adminName,20);
			cout<<"password:";
			cin.getline(pass,10);
			check=1;
			
		}
		void displayAdmin()
		{
			
		}
		int getcheck()//to check whether the acount is created or not
		{
			return check;
		}
		int checkAcess(char *u,char *p)//to check authorized login or not
		{
			if(strcmp(p,pass)==0&&strcmp(u,adminName)==0)
			{
				return 1;
				
			}
			else
			{
				return 0;
			}
		}
		
		
};
void setPass()//this function is to set the username and password for the first time only
{
	admin a;
	fstream f;
	f.open("pass.txt",ios::binary|ios::in);
	f.read(reinterpret_cast<char *>(&a),sizeof(a));
	while(1)
	{
		if(a.getcheck()==1)
		{
		
			break;
		}
		f.close();
		cout<<"--->A complete student evaluation system<---\n";
		cout<<"please Create a admin name and password for the login\n";
		f.open("pass.txt",ios::binary|ios::out);
		a.input();
		f.write(reinterpret_cast<char *>(&a),sizeof(a));
		f.close();
	}
}
void checkPass()//this function is to check if the username and password is correct or not
{
	char adminName[20];
	char pass[10];
	admin a;
	fstream f;
	f.open("pass.txt",ios::binary|ios::in);
	f.read(reinterpret_cast<char *>(&a),sizeof(a));
	if(a.getcheck()!=1)
		{
			cout<<"some error has occured in the program.....";
			exit(0);
		}
	f.close();
	cout<<"----Login Panel---\n";
	cout<<"enter username:";
	cin.getline(adminName,20);
	cout<<"enter the password:";
	char x;
	for(int i=0;i<10;i++)
		{
			x=getch();
			pass[i]=x;
			if(x!='\r')
				{
					cout<<"*";
				}
			if(x=='\r')
				{
					pass[i]='\0';
					break;
											
				}
		}
		if(a.checkAcess(adminName,pass))
		{
			system("cls");
			cout<<"------------------------------------------------------------------------------------------------------------------------\n";
			cout<<setw(80)<<"WELCOME to student evaluation system\n";
			cout<<setw(65)<<"Developed By:\n";
			cout<<endl<<endl;
			cout<<setw(65)<<"->Rikesh Basnet\n";
			cout<<setw(66)<<"->Sagar Bhandari\n";
			cout<<setw(64)<<"->Yogesh Thapa\n";
			cout<<setw(66)<<"->Prashant Yadav\n";
			cout<<endl<<endl;
			cout<<"------------------------------------------------------------------------------------------------------------------------\n";
			
		}
		else
		{
			system("cls");
			cout<<"Acess Denied!!!!!!\n";
			exit(0);
		}
}
void doAttendance()
{
	char cName[10];
	cout<<"enter the classname'eg:BCT074B':";
	cin>>cName;
	fstream f;
	f.open(cName,ios::binary|ios::app);
	f.seekg(0,ios::end);
	
	if(f.tellg()==0)//to store the student name and roll only in the first time
	{
		char ch='y';
		while(ch=='y'||ch=='Y')
		{
			classroom c1;
			c1.intialize();
			f.write(reinterpret_cast<char *>(&c1),sizeof(c1));
			cout<<"do you want to store other(y/n):";
			cin>>ch;
			
		}	
		
	}
	f.close();
    fstream fout;
    classroom c2;
    int count=0;
    int location;
    int size=sizeof(c2);
    fout.open(cName,ios::ate|ios::out|ios::in|ios::binary);
    fout.seekg(0);
    while(fout.read(reinterpret_cast<char *>(&c2),sizeof(c2)))
    {
    	count++;
    	c2.display();
    	location=size*(count-1);
    	fout.seekp(location,ios::beg);
    	fout.write(reinterpret_cast<char *>(&c2),sizeof(c2));
	}
}
void storeTutorial()
{
	char cName[10];
	cout<<"enter the class name 'eg:BCT074B'";
	cin>>cName;
	fstream fout;
    classroom c3;
    int count=0;
    int location;
    int size=sizeof(c3);
    fout.open(cName,ios::ate|ios::out|ios::in|ios::binary);
    fout.seekg(0);
    while(fout.read(reinterpret_cast<char *>(&c3),sizeof(c3)))
    {
    	count++;
    	c3.increaseTut();
    	location=size*(count-1);
    	fout.seekp(location,ios::beg);
    	fout.write(reinterpret_cast<char *>(&c3),sizeof(c3));
	}
}
void storeExam()
{
	int fm;
	l1:
	int n;
	cout<<"1.1st terminal exam\n";
	cout<<"2.final terminal exam\n";
	cin>>n;
	switch(n)
	{
		case 1:
			{
				char cName[10];
				cout<<"enter the class name 'eg:BCT074B'";
				cin>>cName;
				cout<<"enter the fullmarks of the 1st terminal exam: ";
				cin>>fm;
				fstream fout;
			    classroom c4;
			    int count=0;
			    int location;
			    int size=sizeof(c4);
			    fout.open(cName,ios::ate|ios::out|ios::in|ios::binary);
			    fout.seekg(0);
			    while(fout.read(reinterpret_cast<char *>(&c4),sizeof(c4)))
			    {
			    	count++;
			    	c4.increaseMark1(fm);
			    	location=size*(count-1);
			    	fout.seekp(location,ios::beg);
			    	fout.write(reinterpret_cast<char *>(&c4),sizeof(c4));
				}

				break;
				
			}
		case 2:
			{
				
				char cName[10];
				cout<<"enter the class name 'eg:BCT074B'";
				cin>>cName;
				cout<<"enter the fullmarks of the final terminal exam: ";
				cin>>fm;
				fstream fout;
			    classroom c5;
			    int count=0;
			    int location;
			    int size=sizeof(c5);
			    fout.open(cName,ios::ate|ios::out|ios::in|ios::binary);
			    fout.seekg(0);
			    while(fout.read(reinterpret_cast<char *>(&c5),sizeof(c5)))
			    {
			    	count++;
			    	c5.increaseMark2(fm);
			    	location=size*(count-1);
			    	fout.seekp(location,ios::beg);
			    	fout.write(reinterpret_cast<char *>(&c5),sizeof(c5));
				}
				break;
			}
		default:
			goto l1;
			break;
	}
}
void print()
{
	char cName[10];
	cout<<"enter the class name 'eg:BCT074B'";
	cin.sync();
	
	cin.getline(cName,10);
	cout<<col<<"name"<<col<<"roll"<<col<<"attendance"<<col<<"1st exam"<<col<<"2nd exam"<<col<<"tutorial"<<col<<"internalmark"<<endl;
	classroom c6;
	fstream fin;
	fin.open(cName,ios::in);
	while(fin.read(reinterpret_cast<char *>(&c6),sizeof(c6)))
	{
		c6.displayAll();
	}
	getch();
}
void internalMark()
{
	char cName[10];
	cout<<"enter the class name 'eg:BCT074B'";
	cin>>cName;
	int efm;//this is to store the full marks of the internal marks
	int tm;//this is to store the internal marks from the tutorial
	int am;//this is to store the internal marks from the attendance
	int em;//this is to store the internal marks from the internal exam performnace
	cout<<"full marks of the internal marks::"<<ends;
	cin>>efm;
	cout<<"internal marks form the tutorial::"<<ends;
	cin>>tm;
	cout<<"internal marks from the attendance::"<<ends;
	cin>>am;
	cout<<"internal marks from the internal exam performance"<<ends;
	cin>>em;
	fstream fout;
			    classroom c7;
			    int count=0;
			    int location;
			    int size=sizeof(c7);
			    fout.open(cName,ios::ate|ios::out|ios::in|ios::binary);
			    fout.seekg(0);
			    while(fout.read(reinterpret_cast<char *>(&c7),sizeof(c7)))
			    {
			    	int t;
			    	int a;
			    	int e;
			    	count++;
			    	t=((c7.getntut())/(c7.gettntut()))*tm;
			    	a=((c7.getpDays())/(c7.getcDays()))*tm;
			    	e=((c7.getem1()+c7.getem2())/(c7.getefm1()+c7.getefm2()))*e;
			    	c7.increaseInternal(t+a+e);
			    	
			    	
			    	location=size*(count-1);

			    	fout.seekp(location,ios::beg);
			    	fout.write(reinterpret_cast<char *>(&c7),sizeof(c7));
				}
				fout.close();
				fstream fin;
				classroom c9;
				fin.open(cName,ios::in|ios::binary);
				cout<<col<<"name"<<col<<"internal Marks"<<endl;
				while(fin.read(reinterpret_cast<char *>(&c9),sizeof(c9)))
				{
					c9.printInternal();
				}
}
int main()
{
	int n;
	setPass();
	system("cls");
	checkPass();
	getch();
	do
	{
	cout<<"------------------------------------------------------------------------------------------------------------------------\n";
	l1:
	system("cls");
	cout<<setw(65)<<"main menu\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------\n";
	cout<<endl<<endl;
	cout<<setw(67)<<"1.Do attandance\n";
	cout<<endl;
	cout<<setw(75)<<"2.Store tutorial marks\n";
	cout<<endl;
	cout<<setw(79)<<"3.Store internal exam marks\n";
	cout<<endl;
	cout<<setw(72)<<"4.calculate the internal mark\n";
	cout<<endl;
	cout<<setw(72)<<"5.Display all the details\n";
	cout<<endl;
	cout<<setw(58)<<"6.exit\n";
	cout<<endl<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------\n";
	cin>>n;
	switch(n)
	{
		case 1:
			doAttendance();
			break;
		case 2:
			storeTutorial();
			break;
		case 3:
			storeExam();
			break;
		case 4:
			internalMark();
			break;
		case 5:
			print();
			break;
			
		case 6:
			exit(0);
			break;
		default:
			goto l1;
	}
	}while(1);
	system("pause");
}
