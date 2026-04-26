#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int n,x;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }

    cout<<"Original: ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());

    cout<<"\nReverse using library: ";
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }

    vector<int> v2 = v;

    vector<int>::iterator i = v2.begin();
    vector<int>::iterator j = v2.end() - 1;

    while(i < j)
    {
        int temp = *i;
        *i = *j;
        *j = temp;
        i++;
        j--;
    }

    cout<<"\nReverse using iterators: ";
    for(int k=0;k<v2.size();k++)
    {
        cout<<v2[k]<<" ";
    }

    return 0;
}