#include<iostream>
#include<cstring>
using namespace std;

char logg[50][50];
int idx=0;

void addlog(const char *s)
{
    strcpy(logg[idx++], s);
}

class BankAccount
{
    int bal;
public:
    BankAccount()
    {
        bal=0;
    }

    void deposit(int amt)
    {
        addlog("deposit start");

        if(amt<=0)
        {
            throw "Invalid deposit";
        }

        bal+=amt;
        addlog("deposit end");
    }

    void withdraw(int amt)
    {
        addlog("withdraw start");

        if(amt>bal)
        {
            throw "Insufficient balance";
        }

        bal-=amt;
        addlog("withdraw end");
    }

    void show()
    {
        cout<<"Balance = "<<bal<<endl;
    }
};

void processDeposit(BankAccount &b,int amt)
{
    addlog("processDeposit start");
    b.deposit(amt);
    addlog("processDeposit end");
}

void processWithdraw(BankAccount &b,int amt)
{
    addlog("processWithdraw start");
    b.withdraw(amt);
    addlog("processWithdraw end");
}

int main()
{
    BankAccount b;
    int ch,amt;

    do
    {
        cout<<"\n1.Deposit\n2.Withdraw\n3.Show\n4.Exit\nEnter: ";
        cin>>ch;

        try
        {
            if(ch==1)
            {
                cout<<"Enter amount: ";
                cin>>amt;
                processDeposit(b,amt);
            }
            else if(ch==2)
            {
                cout<<"Enter amount: ";
                cin>>amt;
                processWithdraw(b,amt);
            }
            else if(ch==3)
            {
                b.show();
            }
        }
        catch(const char *msg)
        {
            addlog("exception in main");
            cout<<msg<<endl;
        }

    }while(ch!=4);

    cout<<"\nLogs:"<<endl;
    for(int i=0;i<idx;i++)
    {
        cout<<logg[i]<<endl;
    }

    return 0;
}