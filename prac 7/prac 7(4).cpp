
//using dynamic left 
#include<iostream>
using namespace std;
class shape
{
public:
	virtual float area()=0;
	virtual ~shape() {};
};

class rectangle:public shape
{
	float length;
	float breadth;
public:
	void get()
	{
		cout<<"Enter the length "<<endl;
		cin>>length;
		cout<<"Enter the breadth "<<endl;
		cin>>breadth;
	}


	float area() override
	{
		cout<<"The area of rectangle is "<<endl;
		return length*breadth;
	}
};

class circle:public shape
{
	float radius;
public:
	void getdata()
	{
		cout<<"Enter the radius "<<endl;
		cin>>radius;
	}

	float area() override
	{
		cout<<"The area of the circle is "<<endl;
		return 3.14*radius*radius;
	}
};
int main()
{
	shape *ptr;
// 	rectangle r1;
// 	r1.get();
// 	ptr=&r1;
// 	cout<<ptr->area()<<endl;
// 	circle c1;
// 	c1.getdata();
// 	ptr=&c1;
// 	cout<<ptr->area()<<endl;
	int choice=0;
	cout<<"The static way using array is "<<endl;
	cout<<"Enter 1 for rectangle and 2 for circle "<<endl;
	cin>>choice;
	if(choice==1)
	{
	    int n;
	    cout<<"Enter the number of rectangle you want" <<endl;
	    cin>>n;
	    rectangle r[n];
	    for(int i =0;i<n;i++)
	    {
	        cout<<"Enter the details for "<<i+1<<endl;
	        r[i].get();
	    }
	    for(int i =0;i<n;i++)
	    {
	        cout<<r[i].area()<<endl;
	    }
	}
	if(choice==2)
	{
	    int n;
	    cout<<"Enter the number of rectangle you want" <<endl;
	    cin>>n;
	    circle c[n];
	    for(int i =0;i<n;i++)
	    {
	        cout<<"Enter the details for "<<i+1<<endl;
	        c[i].getdata();
	    }
	    for(int i =0;i<n;i++)
	    {
	        cout<<c[i].area()<<endl;
	    }
	}
	return 0;
}