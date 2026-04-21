#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>
T minimum_element(T arr[], int n)
{
	T temp=arr[0];
	for(int i =0; i<n; i++)
	{
		if(arr[i]<temp)
		{
			temp=arr[i];
		}
	}
	return temp;
}
template<typename T>
T maximum_element(T arr[], int n)
{
	T temp=arr[0];
	for(int i =0; i<n; i++)
	{
		if(arr[i]>temp)
		{
			temp=arr[i];
		}
	}
	return temp;
}
template<typename T>
void r(T arr[],int n)
{
	reverse(arr,arr+n);

}

template<typename T>
void display(T arr[],int n)
{
	cout<<"The element of the array is "<<endl;
	for(int i =0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
}
template<typename T>
void max_element(T arr[],int n,T ans[])
{
	T max_right=arr[n-1];
	int count=1;
	ans[0]=max_right;
	 for(int i = n - 2; i >= 0; i--)
    {
        if(arr[i] > max_right)
        {
            max_right = arr[i];
            ans[count++] = arr[i];
        }
    }
	reverse(ans, ans+count);
	
}
int main()
{
	int arr[]= {1,2,4,2,1,4,2,1,54,5,53,121,77};
	int n =sizeof(arr)/sizeof(arr[0]);
	int choice;
	do {
		cout<<"Enter 1 for the Displaying the element "<<endl;
		cout<<"Enter 2 for the reverseing the element "<<endl;
		cout<<"Enter 3 for the findig the greater element"<<endl;
		cout<<"Enter 4 for minimum element "<<endl;
		cout<<"Enter 5 for the maximum element "<<endl;
// 		cout<<"Enter 6 for counting the element"<<endl;
		cout<<"Enter 7 for exit "<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
		{
			display( arr, n);
			cout<<endl;
			break;
		}
		case 2:
		{
			int temp[n];
			for(int i =0; i<n; i++)
			{
				temp[i]=arr[i];
			}
			r(temp,n);
			cout<<"The reverse of the array is :"<<endl;
			for(int i =0; i<n; i++)
			{
				cout<<temp[i]<<" ";
			}
			cout<<endl;
			break;
		}
		case 3:
		{
			int ans[n]= {0};
			max_element(arr,n,ans);
			cout<<"The maximum elements are "<<endl;
			for(int i =0; i<5; i++)
			{
				cout<<ans[i]<<" ";
			}
			cout<<endl;
			break;
		}
		case 4:
		{
			cout<<"The minimum element is "<<minimum_element(arr, n);
			cout<<endl;
			break;
		}
		case 5:
		{
			cout<<"The maximum element is "<<maximum_element(arr, n);
			cout<<endl;
			break;
		}
// 		case 6:
// 		{
// 			template<typename T>
// 			map<T, T> count;

// 			break;
// 		}
		case 7 : {
			cout<<"Exiting "<<endl;
			cout<<endl;
			break;
		}
		default : {
			cout<<"Invalid choice !! Pls try again"<<endl;
			cout<<endl;
			break;
		}
		}
	} while(choice!=7);
	return 0;
}