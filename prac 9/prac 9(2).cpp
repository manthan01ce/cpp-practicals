#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,int> m;
    string s, word;

    cout<<"Enter sentence: ";
    getline(cin,s);

    for(int i=0;i<=s.length();i++)
    {
        if(s[i]==' ' || s[i]=='\0')
        {
            if(word!="")
            {
                m[word]++;
                word="";
            }
        }
        else
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                word += s[i] + 32;
            }
            else
            {
                word += s[i];
            }
        }
    }

    cout<<"\nWord Frequency:\n";
    for(auto i=m.begin(); i!=m.end(); i++)
    {
        cout<<i->first<<" : "<<i->second<<endl;
    }

    return 0;
}