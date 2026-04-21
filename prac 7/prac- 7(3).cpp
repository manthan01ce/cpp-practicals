
//the conversion using the dynamic que is left 
#include<iostream>
using namespace std;
class farhenite;
class celsius
{
	float c;
public:
	celsius()
	{
	}
	celsius(float f)
	{
		this->c=f;
	}
	celsius(farhenite f);
	float  get_c()
	{
		return c;
	}
	void putdata()
	{
		cout<<"The temperature in celsius is "<<c<<endl;
	}
	bool operator==(celsius x)
	{
		return c==x.c;
	}
};

class farhenite
{
	float f;
public:
	farhenite()
	{
	}
	farhenite(float x)
	{
	    f=x;
	}
	farhenite(celsius x)
	{
		f = (x.get_c() * 9/5) + 32;
	}
	float get_f()
	{
		return f;
	}
	void put()
	{
		cout<<"The temperature in farhenite is "<<f<<endl;
	}
};
celsius::celsius(farhenite f)
{
	{
		c = (f.get_f() - 32) * 5/9;
	}
}
int main()
{
	celsius c1(100.0);
	farhenite f1;
	f1=c1;
	f1.put();
	celsius c2;
	farhenite f2(80.0);
	c2=f2;
	c2.putdata();
	if(c2==c1)
	{
		cout<<"Equal"<<endl;
	} else
	{
		cout<<"Not equal"<<endl;
	}
	int choice=0;
    cout<<"Enter 1 for conversion of the celsius to farhenite"<<endl;
    cout<<"Enter 2 for conversion of the farhenite to celsius"<<endl;
    cin>>choice;
    
    if(choice==1)
    {
        int n;
        cout<<"Enter the number of conversion you want"<<endl;
        cin>>n;
        celsius c[n];
        farhenite f[n];
        for(int i =0;i<n;i++)
        {
            float temp;
            cout<<"Enter the temp "<<i+1<<endl;
            cin>>temp;
            c[i]=celsius(temp);
            f[i]=c[i];
        }
        for(int i =0;i<n;i++)
        {
            cout<<"Ther temperature "<<i+1 <<" in farhenite is ";
            f[i].put();
            cout<<endl;
        }
    }else if(choice==2)
    {
        int n;
        cout<<"Enter the number of conversion you want"<<endl;
        cin>>n;
        celsius c[n];
        farhenite f[n];
        for(int i =0;i<n;i++)
        {
            float temp;
            cout<<"Enter the temp "<<i+1<<endl;
            cin>>temp;
            f[i]=farhenite(temp);
            c[i]=f[i];
        }
        for(int i =0;i<n;i++)
        {
            cout<<"Ther temperature "<<i+1 <<" in celsius is ";
            c[i].putdata();
            cout<<endl;
        }
    }else
    {
        cout<<"Invalid choice "<<endl;
    }
	return 0;
}