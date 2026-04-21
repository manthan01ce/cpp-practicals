#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
class shape
{
	int radius;
public:
	void get_data();
	void put_data();
	int get_r();
};
int shape::get_r()
{
	return radius;
}

class circle: public shape
{
public:
	float area();
	float circum();
};

float circle::circum()
{
    return 2*3.14*get_r();
}
float circle::area()
{
	float ans=3.14*get_r();
	ans*=get_r();
	return ans;
}
void shape::get_data()
{
	cout<<"Enter the radius "<<endl;
	cin>>radius;
}
void shape::put_data()
{
	cout<<"The radius is "<<radius<<endl;
}
int main()
{
	int choice=0;
	int flag=0;
	vector<circle>count;//new thing :creating vector of the class
	do {
		cout<<"Enter 1 for adding the circle "<<endl;
		cout<<"Enter 2 for seeing the area of circle "<<endl;
		cout<<"Enter 3 for seeing the area circumferance and radius in tabular form "<<endl;
		cin>>choice;
		if(choice==1)
		{
			circle temp;
			temp.get_data();
			count.push_back(temp);
			count[flag].put_data();
			cout<<"Success"<<endl;
			flag++;
		} else if(choice ==2)
		{
			for(int i =0; i<flag; i++)
			{
				cout<<"The area is "<<count[i].area()<<endl;
			}
		}
		else if(choice==3) {
				cout<<"-------------------------------------------"<<endl;
				cout<<setw(10)<<"Radius"<<setw(12)<<"Area"<<setw(20)<<"circumferance"<<endl;
				cout<<"-------------------------------------------"<<endl;
			for(int i =0; i<flag; i++)
			{
				cout<<setw(8)<<count[i].get_r()<<setw(13)<<count[i].area()<<setw(12)<<count[i].circum()<<endl;
				cout<<"------------------------------------------"<<endl;
			}
		} else
		{
			cout<<"exiting"<<endl;
			break;
		}
	} while(choice!=4);
	return 0;
}