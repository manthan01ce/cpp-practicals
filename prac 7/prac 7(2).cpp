#include<iostream>
using namespace std;

class complex
{
    int a;
    int b;
    public:
    
    void getdata()
    {
        cout<<"Enter the number 1 "<<endl;
        cin>>a;
        cout<<"Enter the number 2 "<<endl;
        cin>>b;
    }
    
    void putdata()
    {
        cout<<"The number is "<<a<<" "<<b<<endl;
    }
    
    complex operator+(complex x)
    {
        complex temp;
        temp.a=a+x.a;
        temp.b=b+x.b;
       return temp;   
    }
    
     complex operator-(complex x)
    {
        complex temp;
        temp.a=a-x.a;
        temp.b=b-x.b;
       return temp;   
    }
};
int main()
{
    complex c1,c2,c3,c4;
    c1.getdata();
    c2.getdata();
    c3=c1+c2;
    c3.putdata();
    c4=c2-c1;
    c4.putdata();
    return 0;
}