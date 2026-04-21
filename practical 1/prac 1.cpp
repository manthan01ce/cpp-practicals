#include<iostream>
using namespace std;

class  wallet {
	int wallet_id;
	string name;
	float balance;

public:
	void get_info();
	void put_info();
	bool get_id(int temp_id);
	void change_balance(float amount);
	void show_walletid();
	bool minus_balance(float amount);
};
bool wallet::minus_balance(float amount)
{
    if(amount>balance)
    {
        cout<<"Insufficient balance"<<endl;
        return false;
    }else{
	balance-=amount;
	return true;
    }
}
void wallet::show_walletid()
{
	cout<<wallet_id<<endl;
}
void wallet::change_balance(float amount)
{

	balance+=amount;
	cout<<"tranferred succesfully"<<endl;
}
bool wallet::get_id(int temp_id)
{
	return temp_id=wallet_id;
}
void wallet::get_info()
{
	cout<<"Enter the wallet ID number"<<endl;
	cin>>wallet_id;
	cout<<"Enter the name of the user"<<endl;
	cin.ignore();
	getline(cin, name);
	cout<<"Enter the balance you are keeping"<<endl;
	cin>>balance;
}

void wallet::put_info()
{
	cout<<"The wallet ID number is "<<wallet_id<<endl;
	cout<<"The name of the user is "<<name<<endl;
	cout<<"The balance of the user: "<<balance<<endl;
}
int main()
{
	int choice=0,flag=0;
			float amount=0;
	wallet w[20];
	do {
		cout<<"Enter 1 for creating wallet "<<endl<<"Enter 2 for the transferring money to another wallet"<<endl;
		cout<<"Enter for depositing money in your wallet"<<endl<<"Enter 4 for seeing details"<<endl;
		cout<<"Enter 5 for the exit"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1: {
			w[flag].get_info();
			flag++;
			cout<<"The details are stored succesfully"<<endl;
			break;
		}
		case 2: {
		    if(flag==0)
		    {
		        cout<<"Pls register for  te wallet id in bank"<<endl;
		        break;
		    }
			int my_id=0;
			cout<<"Enter your id for further transaction "<<endl;
			cin>>my_id;
			bool found=false;
			for(int i=0; i<flag; i++)
			{
				if(w[i].get_id(my_id))
				{
					cout<<"Enter the amount to be tranferred "<<endl;
					cin>>amount;
					if(w[i].minus_balance(amount))
					{
					cout<<"The ID in our bank are "<<endl;
					for(int i =0; i<flag; i++)
					{
						w[i].show_walletid();
					}
					int temp_id=0;
					cout<<"Enter the id of the wallet you want to tranfer money from your"<<endl;
					cin>>temp_id;

					found=false;
					for(int i=0; i<flag; i++)
					{
						if(w[i].get_id(temp_id)==true)
						{
							w[i].change_balance(amount);
							found=true;
						}
					}
					if(!found)
					{
						cout<<"Invalid wallet id number"<<endl;
						break;
					}
					}
				

				}
			}
			if(!found)
			{
				cout<<"Invalid wallet id number"<<endl;
				break;
			}
			break;
        }
        case 3:{
            if(flag==0)
		    {
		        cout<<"Pls register for  te wallet id in bank"<<endl;
		        break;
		    }
            int temp_id=0;
            cout<<"Enter your wallet id for depositing amount"<<endl;
            cin>>temp_id;
            bool found=false;
            for(int i=0;i<flag;i++)
            {
                if(w[i].get_id(temp_id))
                {
                    cout<<"Enter the amount to be deposited"<<endl;
                    cin>>amount;
                    w[i].change_balance(amount);
                    found=true;
                }

            }
            if(!found)
					{
						cout<<"Invalid wallet id number"<<endl;
						break;
					}
					break;
        }
        case 4:{
            if(flag==0)
		    {
		        cout<<"Pls register for  te wallet id in bank"<<endl;
		        break;
		    }
            int temp_id=0;
            cout<<"Enter your wallet id for seeing details"<<endl;
            cin>>temp_id;
            bool found=false;
            for(int i=0;i<flag;i++)
            {
                if(w[i].get_id(temp_id))
                {
                    w[i].put_info();
                    found=true;
                }

            }
            if(!found)
					{
						cout<<"Invalid wallet id number"<<endl;
						break;
					}
					break;
        }
        case 5:{
            cout<<"Exiting"<<endl;
            break;
        }
        default:{
            cout<<"Invalid choice "<<endl;
            break;
        }
        
		}
	}while(choice!=5);
	return 0;
}