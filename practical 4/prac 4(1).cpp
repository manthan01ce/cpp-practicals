#include<iostream>
using namespace std;
#include<map>

void display(int *ptr, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<ptr[i]<<" ";
    }
}
int search_element(int *ptr, int n, int search)
{
    bool found=false;
    for(int i =0;i<n;i++)
    {
        if(ptr[i]==search)
        {
            found=true;
            return i+1;
        }
    }
    if(!found)
    {
        return -1;
    }
}
int main()
{
    int n;
    cout<<"Enter the array size"<<endl;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    int *ptr=arr;
    int choice=0;
    do{
        cout<<"Enter 1 for the inserting the element at end of the array "<<endl;
        cout<<"Enter 2 for delete the specific element of the array      "<<endl;
        cout<<"Enter 3 for Display the current array element             "<<endl;
        cout<<"Enter 4 for adding element at specific index of the array "<<endl;
        cout<<"Enter 5 for searching element from the array element"<<endl;
        cout<<"Enter 6 for seeing the occurance of the element in the array "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:{
                int last=0;
                int *ptr2= new int[n+1];
                cout<<"Enter the new element added to the end of the array"<<endl;
                cin>>last;
                for(int i =0;i<n;i++)
                {
                    ptr2[i]=ptr[i];
                }
                ptr2[n]=last;
                ptr=ptr2;
                n++;
                cout<<endl;
                break;
            }
            case 2:
            {
                int index=0;
                cout<<"Enter the element position you want to delete form the array "<<endl;
                cin>>index;
                for(int i =index-1;i<n-1;i++)
                {
                    ptr[i]=ptr[i+1];
                }
                n--;
                break;
            }
            case 3:
            {
                display(ptr, n);
                cout<<endl;
                break;
            }
            case 4:{
                int element=0;
                int index=0;
                cout<<"Enter the index of the element you want to add"<<endl;
                cin>>index;
                cout<<"Enter the element value "<<endl;
                cin>>element;
                int *ptr2= new int[n+1];
                for(int i =0,j=0;i<n+1;i++)
                {
                    if(i==index-1)
                    {
                        ptr2[i]=element;
                        
                    }else{
                            ptr2[i]=ptr[j];
                            j++;
                         }
                }
                ptr=ptr2;
                n++;
                break;
            }
            case 5 :{
                int search=0;
                cout<<"Enter the element to be searched"<<endl;
                cin>>search;
                cout<<"The index for the element is "<<search_element(ptr, n, search)<<endl;
                break;
            }
            case 6:
            {
                map<int , int>count;
                for(int i=0;i<n;i++)
                {
                    int temp=ptr[i];
                    count[temp]++;
                }
                for(auto &x:count)
                {
                    cout<<x.first <<" occured "<<x.second<<" times"<<endl;
                }
                break;
            }
            case 7:
            {
                cout<<"Exiting !!"<<endl;
                break;
            }
            default :
            {
                cout<<"Invalid choice!! Pls try again"<<endl;
                break;
            }
        }
        
    }while(choice!=7);
    
    return 0;
}