#include<iostream>
using namespace std;

class student_info
{
	int roll_number;
	string name;
	float marks1,marks2,marks3;
	float average;

public:
	void getdata()
	{
		cout<<"Enter the name "<<endl;
		cin>>name;
		cout<<"Enter the roll number"<<endl;
		cin>>roll_number;
		cout<<"Enter the marks 1 2 and 3 respectively"<<endl;
		cin>>marks1>>marks2>>marks3;
		if(marks1 < 0 || marks1 > 100 ||
		        marks2 < 0 || marks2 > 100 ||
		        marks3 < 0 || marks3 > 100)
		{
			cout<<"Invalid marks. Student not added.\n";
			return;   // exit function
		}
		average=average_marks();
	}

	student_info()//Default constructor
	{
		roll_number=1;
		name= "Default name";
		marks1=90;
		marks2=91;
		marks3=98;
		average=average_marks();
	}

	bool check_roll(int temp_roll);
	student_info(int r, float m1,float m2,float m3, string n)
	{
		roll_number=r;
		marks3=m3;
		marks2=m2;
		marks1=m1;
		name=n;
		average=average_marks();
	}

	float average_marks();
	void display();

};


float student_info::average_marks()
{
	return (marks1+marks2+marks3)/3.0;
}
void student_info::display()
{
	cout<<"The name of the student is         :"<<name<<endl;
	cout<<"The roll numbe of the student is   :"<<roll_number<<endl;
	if(average>=80 and average<=90)
	{
		cout<<"The grade is  'A' "<<endl;
	} else if(average>=70 and average<=79)
	{
		cout<<"The grade is 'B' "<<endl;
	} else if(average>=50 and average<=69)
	{
		cout<<"The grade is 'C' "<<endl;
	}
	cout<<"The average marks of the student is:"<<average<<endl;
}
bool student_info::check_roll(int temp_roll)
{
	return temp_roll==roll_number;
}
int main()
{
	int flag=0;
	int choice=0;
	student_info s[10];
	//initializing the student by default for 3 student
	student_info s1;
	flag++;
	do {
x:
		cout<<"Enter 1 for the new student entry"<<endl<<"Enter 2 for the viewing the detail"<<endl;
		cout<<"Enter 3 for exit"<<endl;
		cin>>choice;

		if(choice==1)
		{
			if(flag>10)
			{
				cout<<"No space"<<endl;
				break;
			}
			s[flag].getdata();
			flag++;
		}
		else if(choice==2)
		{
			int temp_roll;
			cout<<"Enter the roll number to see detail"<<endl;
			cin>>temp_roll;
			bool found=false;
			for(int i=0; i<flag; i++)
			{
				if(s[i].check_roll(temp_roll))
				{
					s[i].display();
					found=true;
					break;
				}
			}
			if(!found)
			{
				cout<<"Student does not exists"<<endl;
				goto x;
			}
		}
		else {
			cout<<"Exit"<<endl;
			break;
		}
	} while(choice!=3);

	return 0;
}