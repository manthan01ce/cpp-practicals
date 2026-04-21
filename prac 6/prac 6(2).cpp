 #include<iostream>
using namespace std;
#include<vector>
class person
{
	string name;
	int age;
public:
	void putdata();
	person(string n, int a)
	{
		this->name=n;
		this->age=a;
	}
};

void person:: putdata()
{
	cout<<"The name of the person is "<<name<<endl;
	cout<<"The age  of the person is "<<age<<endl;
}


class employee:public person
{
	int id;
public:
	void p_data();
	int get_id()
	{
		return id;
	}
	employee(int Id, string Name, int Age):person(Name, Age)
	{
		this->id=Id;
	}
};
void employee::p_data()
{
    putdata();
	cout<<"the ID of the employee is "<<id<<endl;
}

class manager:public employee
{
	string department;
public:
	void input();
	void output();

	manager(string d, int Id, string Name, int Age):employee(Id,Name, Age)
	{
		this->department=d;
	}
};
void manager::input()
{
	cout<<"Enter the department of the employee"<<endl;
	cin.ignore();
	getline(cin, department);

	cout<<"Success"<<endl;
}
void manager::output()
{
    p_data();
	cout<<"The department of the employee is "<<department<<endl;
}
int main()
{
	vector<manager> count;
	int choice=0;
	do {
		cout<<"Enter 1 for adding new entry "<<endl;
		cout<<"Enter 2 for the searching the employee"<<endl;
		cout<<"Enter 3 for displaying details"<<endl;
		cin>>choice;
		if(choice==1)
		{
			string Name;
			int Age=0;
			int Id=0;
			string d;
			cout<<"Enter the name of the peron "<<endl;
			cin.ignore();
			getline(cin, Name);
			cout<<"Enter the age of the person"<<endl;
			cin>>Age;
			cout<<"Sucess"<<endl;
			cout<<"Enter the ID of the employee"<<endl;
			cin>>Id;
			cout<<"success"<<endl;
			cout<<"Enter the department of the employee"<<endl;
			cin.ignore();
			getline(cin, d);
			cout<<"Success"<<endl;


			manager m(d,Id,Name, Age);
			count.push_back(m);
		} else if(choice==2)
		{
			int temp_id=0;
			cout<<"Enter the ID of the employee"<<endl;
			cin>>temp_id;
			bool found=0;
			for(int i =0; i<count.size(); i++)
			{
				if(temp_id==count[i].get_id())
				{
					cout<<"employee found "<<endl;
					count[i].putdata();
					count[i].p_data();
					count[i].output();
					found=1;
					break;
				}
			}
			if(found==0)
			{
			    cout<<"employee does not exits"<<endl;
			}
		}
		else if(choice==3)
		{
			for(int i =0; i<count.size(); i++)
			{
				count[i].output();
			}
		} else
		{
			cout<<"Invalid choice"<<endl;
		}
	} while(choice!=4);
	return 0;
}