#include<iostream>
using namespace std;
class point
{
    int x;
    int y;
    public:
    void getdata()
    {
        cout<<"Enter for first "<<endl;
        cin>>x;
        cout<<"Enter for the second"<<endl;
        cin>>y;
    }
    void putdata()
    {
        cout<<"The x is :"<<x<<endl;
        cout<<"The y is :"<<y<<endl;
    }
    point& move(int dx, int dy)//this is because we need to pass the reference not copy.
    {
        this->x+=dx;
        this->y+=dy;
        return *this;//it just returns the address and then vanishes.
    }
};
int main()
{
    point p;
    p.getdata();
    p.move(1,2).move(1,2);//first in line is always called first.
    p.putdata();
    return 0;
}