#include<iostream>
using namespace std;
class rectangle {
	float length;
	float breadth;
	int ID;
public:
	void get_info();
	void show_info();
	void area_perimeter();
	float get_length();
	float get_breadth();
	void change_info();
	int get_ID();

};


int rectangle::get_ID()
{
	return ID;
}
void rectangle::change_info()
{
	cout<<"Enter the new length  and breadth"<<endl;
	cin>>length>>breadth;
}

float rectangle::get_length()
{
	return length;
}

float rectangle::get_breadth()
{
	return breadth;
}

void rectangle::area_perimeter()
{
	cout<<"The area of the rectangle is "<<length*breadth<<endl;
	cout<<"The perimeter of the rectangle is"<<2*(length+breadth)<<endl;
}
void rectangle::get_info()
{
	cout<<"Enter the length for the rectangle"<<endl;
	cin>>length;
	cout<<"Enter the breadth for the rectangle"<<endl;
	cin>>breadth;
	cout<<"Enter an ID for these rectangle"<<endl;
	cin>>ID;
}

void rectangle::show_info()
{
	cout<<"The length of the rectangle is  "<<length<<endl;
	cout<<"The breadth of the rectangle is "<<breadth<<endl;
}


int main()
{
	int choice =0,flag=0;
	rectangle r[10];
	do {
		cout<<"Enter 1 for adding details of rectangle"<<endl<<"Enter 2 for changing the details"<<endl<<"Enter 3 for seeing the area and perimeter"<<endl;
		cout<<"Enter 4 for comaparing the two rectangle"<<endl<<"Enter 5 for exit"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1: {
			if(flag>=10)
			{
				cout<<"maximum stored no space"<<endl;
			}
			r[flag].get_info();
			if(r[flag].get_length()<=0 or r[flag].get_breadth()<=0)
			{
			    cout<<"Invalid lenght or breadth"<<endl;
			    cout<<"Pls enter valid length or breadth"<<endl;
			    break;
			}else if(r[flag].get_breadth()==r[flag].get_length())
			{
			    cout<<"Invalid because it is an square not rectangle"<<endl;
			    break;
			}
			flag++;
			break;
		}
		case 2:
		{
			int temp_ID;
			cout<<"Enter the ID of the rectangle details you want"<<endl;
			cin>>temp_ID;
			bool found = false;
			for(int i =0; i<flag; i++)
			{
				if(r[i].get_ID()==temp_ID)
				{
					r[i].change_info();
					cout<<endl;
					found=true;
				}
			}
			if(!found)
			{
				cout<<"no rectangle of these ID"<<endl;
			}

			break;
		}
		case 3:
		{
			int temp_ID;
			cout<<"Enter the ID of the rectangle details you want"<<endl;
			cin>>temp_ID;
			bool found = false;
			for(int i =0; i<flag; i++)
			{
				if(r[i].get_ID()==temp_ID)
				{
					r[i].show_info();
					r[i].area_perimeter();
					cout<<endl;
					found=true;
				}
			}
			if(!found)
			{
				cout<<"no rectangle of these ID"<<endl;
			}

			break;
		}
		case 4:
		{
		    int temp_ID1,temp_ID2,temp_length1,temp_breadth1,temp_length2,temp_breadth2;
		    cout<<"Enter the ID of the two rectangle you want to compare"<<endl;
		    cin>>temp_ID1>>temp_ID2;
		    bool found=false;
		    for(int i=0;i<flag;i++)
		    {
		        if(r[i].get_ID()==temp_ID1)
		        {
		            if(r[i].get_ID()==temp_ID2);
		            {
		           temp_length1= r[i].get_length();
		           temp_breadth1= r[i].get_breadth();
		           found=true;
}		        }
		    }
		    for(int i=0;i<flag;i++)
		    {
		        if(r[i].get_ID()==temp_ID2)
		        {
		           temp_length2= r[i].get_length();
		           temp_breadth2= r[i].get_breadth();
		           found=true;
		        }
		    }
		    if(!found)
		    {
		        cout<<"The id number is invalid"<<endl;
		        break;
		    }
		    
		    int temp_area1=temp_length1*temp_breadth1;
		    int temp_area2=temp_length2*temp_breadth2;
		    if(temp_area1>temp_area2)
		    {
		        cout<<"The rectangle of ID "<<temp_ID1<<" is greater then the second rectangle by "<<(temp_area1-temp_area2)<<endl;
		        
		    }else
		    {
		      cout<<"The rectangle of ID "<<temp_ID2<<" is greater then the first rectangle by "<<(temp_area2-temp_area1)<<endl;
		    }
		    break;
		}
		case 5:
		{
			break;
		}
		}
	} while(choice!=5);
	return 0;
}