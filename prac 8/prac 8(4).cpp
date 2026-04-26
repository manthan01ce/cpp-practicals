#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    char fname[100];
    ifstream fin;
    int num, sum=0, count=0;
    int lineno=0;

    while(1)
    {
        cout<<"Enter file name: ";
        cin>>fname;

        fin.open(fname);

        if(fin)
        {
            break;
        }
        else
        {
            cout<<"File not found. Try again (y/n): ";
            char ch;
            cin>>ch;
            if(ch=='n' || ch=='N')
            {
                return 0;
            }
        }
    }

    while(fin>>num)
    {
        lineno++;

        if(fin.fail())
        {
            cout<<"Invalid data at line "<<lineno<<endl;
            fin.clear();
            fin.ignore(1000,'\n');
            continue;
        }

        sum+=num;
        count++;
    }

    cout<<"Sum = "<<sum<<endl;

    if(count>0)
    {
        cout<<"Average = "<<(float)sum/count<<endl;
    }
    else
    {
        cout<<"No valid data"<<endl;
    }

    fin.close();

    return 0;
}