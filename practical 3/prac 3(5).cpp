//                  USING FUCNTION
// #include<iostream>
// using namespace std;
// int superdigit_sum(long long sum)
// {
//     while(sum>9)
//     {
//     int digit_sum=0;
//     while(sum!=0)
//     {
//         digit_sum+=sum%10;
//         sum/=10;
//     }
//     sum=digit_sum;
//     }
//     return sum;
// }
// int main()
// {
//     int n;
//     cout<<"Enter the number"<<endl;
//     cin>>n;
//     int k;
//     cin>>k;
//     int num=0;
//     long long sum=0;
//     while(n!=0)
//     {
//         sum+=n%10;
//         n/=10;
//     }
//     sum=k*sum;
    
//     cout<<"The super digit sum is "<<superdigit_sum(sum)<<endl;
//     return 0;
// }

//            USING RECURSION
#include<iostream>
using namespace std;
int superdigit_sum(long long sum)
{
    if(sum<10)
    {
        return sum;
    }
    long long digit_sum=0;
    while(sum!=0)
    {
        digit_sum+=sum%10;
        sum/=10;
    }
   
    return superdigit_sum(digit_sum);
}
int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    int k;
    cin>>k;
    int num=0;
    long long sum=0;
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    sum=k*sum;
    
    cout<<"The super digit sum is "<<superdigit_sum(sum)<<endl;
    return 0;
}