#include<iostream>
#include<iomanip>
using namespace std;
    ostream& currency(ostream& obj)  {
        obj<<"$";
        return obj;
    }
int main()
{
    cout<<"---------------------------------------"<<endl;
    cout<<setw(9)<<"Name "<<setw(15)<<"Marks "<<setw(15)<<" Fees"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"1. Manthan"<<setw(10)<<"99"<<setw(15)<<currency<<"5000000"<<endl;
    cout<<"2. Charusat "<<setw(8)<<"20"<<setw(15)<<currency<<"150"<<endl;
    cout<<"---------------------------------------"<<endl;
    return 0;
}