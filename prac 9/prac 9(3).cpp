#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main()
{
    set<int> s;
    vector<int> v;
    int n,x;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
        s.insert(x);
    }

    cout<<"Original: ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    cout<<"\nUnique sorted (set): ";
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }

    vector<int> v2(s.begin(), s.end());

    cout<<"\nConverted to vector: ";
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }

    return 0;
}