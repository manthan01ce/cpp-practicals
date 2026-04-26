#include<iostream>
#include<cmath>
using namespace std;

class NegativeNumberException
{
};

int main()
{
    double n;

    cout<<"Enter number: ";
    cin>>n;

    try
    {
        if(n < 0)
        {
            throw NegativeNumberException();
        }

        cout<<"Square root = "<<sqrt(n)<<endl;
    }

    catch(NegativeNumberException)
    {
        cout<<"Negative number not allowed"<<endl;
    }

    return 0;
}