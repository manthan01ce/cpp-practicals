#include<iostream>
using namespace std;

int main()
{
    int a,b;

    try
    {
        cout<<"Enter two integers: ";
        cin>>a>>b;

        if(cin.fail())
        {
            throw "Invalid input";
        }

        if(b==0)
        {
            throw b;
        }

        cout<<"Division = "<<a/b<<endl;
    }

    catch(const char* msg)
    {
        cout<<msg<<endl;
    }

    catch(int)
    {
        cout<<"Division by zero"<<endl;
    }

    return 0;
}