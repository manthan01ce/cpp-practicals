#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;
int main()
{
    auto t1 =high_resolution_clock::now();

    int arr[10000],sum=0;
    for(int i=0;i<1000;i++)
    {
        arr[i]=i+30;
        sum+=arr[i];
}
    auto t2 = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(t2-t1);

    cout<<"Time "<<duration.count()<<" ns";
    cout<<"Sum"<< sum<<endl;
}

// #include<iostream>
// #include<chrono>
// using namespace std;
// int sum(int arr[], int x)
// {
//     if(x==0)
//     {
//         return 0;
//     }
//     return arr[x-1]+sum(arr,x-1);
// }
// int main()
// {
//     int arr[100000];
//     for(int i =0 ;i<100000;i++)
//     {
//         arr[i]+=i+30;
//     }
    
//     auto t1= chrono::high_resolution_clock::now();
//     int result = sum(arr,100000);
//     auto t2= chrono::high_resolution_clock::now();
    
//     auto diff= chrono::duration_cast<chrono::nanoseconds>(t2-t1);
//     cout<<diff.count()<<"ns"<< endl;
    
//     return 0;
// }