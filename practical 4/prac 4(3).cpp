#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the size of the first array "<<endl;
    cin>>n;
    cout<<"Enter the size  for the second array "<<endl;
    cin>>m;
    int *ptr1= new int[n];
    int *ptr2= new int[m];
    cout<<"Enter the value for the first array"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>ptr1[i];
    }
    cout<<"Enter the value for the second array "<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>ptr2[i];
    }
    
    int *ptr3= new int[n+m];
    int count=0;
    for( int i =0;i<n;i++)
    {
        ptr3[count]=ptr1[i];
        count++;
    }
    for(int i =0;i<m;i++)
    {
        ptr3[count]=ptr2[i];
        count++;
    }
    
    cout<<"The first array is "<<endl;
    for(int i =0;i<n;i++)
    {
        cout<<ptr1[i]<<" ";
    }
    cout<<endl;
    cout<<"The second array is "<<endl;
    for(int i =0;i<m;i++)
    {
        cout<<ptr2[i]<<" ";
    }
    cout<<endl;
    cout<<"The merged array is "<<endl;
    for(int i =0;i<m+n;i++)
    {
        cout<<ptr3[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}