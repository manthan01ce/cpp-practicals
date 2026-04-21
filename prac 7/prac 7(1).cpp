#include<iostream>
using namespace std;

int add(int x ,int y)
{
    return x+y;
}

float add(float x, float y)
{
    return x+y;
}

double add(double x, double y)
{
    return x+y;
}

float add(int x, float y)
{
    return x+y;
}

double add(int x, double y)
{
    return x+y;
}
int main()
{
    cout<<add(5,1)<<endl;
    cout<<add(5.0f, 6.0f)<<endl;
    cout<<add(5.9, 6.1)<<endl;
    cout<<add(6, 6.7f)<<endl;
    cout<<add(6, 6.7)<<endl;
    return 0;
}