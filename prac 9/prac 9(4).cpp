#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main()
{
    map<string, vector<string>> dir;
    int ch;
    string folder, file;

    do
    {
        cout<<"\n1.Add Folder\n2.Add File\n3.Display\n4.Exit\nEnter: ";
        cin>>ch;

        if(ch==1)
        {
            cout<<"Enter folder name: ";
            cin>>folder;
            dir[folder];
        }
        else if(ch==2)
        {
            cout<<"Enter folder name: ";
            cin>>folder;

            if(dir.find(folder)!=dir.end())
            {
                cout<<"Enter file name: ";
                cin>>file;
                dir[folder].push_back(file);
            }
            else
            {
                cout<<"Folder not found"<<endl;
            }
        }
        else if(ch==3)
        {
            for(map<string, vector<string>>::iterator it=dir.begin(); it!=dir.end(); it++)
            {
                cout<<"\n"<<it->first<<":"<<endl;

                for(int i=0;i<it->second.size();i++)
                {
                    cout<<it->second[i]<<endl;
                }
            }
        }

    } while(ch!=4);

    return 0;
}