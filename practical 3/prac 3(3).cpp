#include<iostream>
using namespace std;
class bank
{
	int  acc_number;
	string name;
	float balance;
	int pin;
public:
	bank(int a, string n, float b, int p)
	{
		acc_number=a;
		name=n;
		balance=b;
		pin=p;
	}
	bank(string n,int a, float b)
	{
		name=n;
		acc_number=a;
		balance=b;
	}


	void putdata();
	bool get_account(int temp_accno);
	bool get_pin(int temp_pin);
	float get_balance();
	void transfer_add(float temp_Amount);
	void transfer_minus(float temp_Amount);
	string get_name();
};

string bank::get_name()
{
	return name;
}
void bank:: transfer_minus(float temp_Amount)
{
	balance-=temp_Amount;
}
void bank:: transfer_add(float temp_Amount)
{
	balance+=temp_Amount;

}
float bank::get_balance()
{
	return balance;
}

bool bank::get_pin(int temp_pin)
{
	return temp_pin==pin;
}


bool bank::get_account(int temp_accno)
{
	return temp_accno==acc_number;
}


void bank::putdata()
{
	cout<<"The account number is "<<acc_number<<endl;
	cout<<"The name  is "<<name<<endl;
	cout<<"The balance is "<<balance<<endl;
}


int main()
{
	bank *ptr[100];
	int choice=0;
	int temp_accno;
	bool found=false;
	float temp_Amount;
	int temp_pin;
	static int count=0;
	do {
		cout<<"Enter 1 for new account creation "<<endl<<"Enter 2 for the transfer to other accounts "<<endl<<"Enter 3 for the withdrawal "<<endl;
		cout<<"Enter 4 for the deposit "<<endl<<"Enter 5 for the updating details "<<endl<<"Enter 6 for seeing the total account in your bank"<<endl;
		cout<<"Enter 7 for seeing the details  "<<endl<<"Enter 8 for the exiting"<<endl;

		cin>>choice;

		switch(choice)
		{
		case 1:
		{
			string n;
			float b;
			int p, a;
			cout<<"Enter the name of the person "<<endl;
			cin.ignore();
			getline(cin, n);
			cout<<"Enter the account number "<<endl;
			cin>>a;
			cout<<"Enter the balance you want to keep in your account "<<endl;
			cin>>b;
			cout<<"Enter the security pin:"<<endl;
			cin>>p;
			ptr[count]= new bank(a,n,b,p);
			count++;
			cout<<"Succesfully stored"<<endl;
			break;
		}
		case 2:
		{
		    
			if(count == 0)
			{
				cout << "Pls make an account first " << endl;
				break;
			}

			int temp_usernnum; 
			cout << "Enter your account number: " << endl;
			cin >> temp_usernnum;
			found = false;

			for(int i = 0; i < count; i++)
			{
				if(ptr[i]->get_account(temp_usernnum)) 
				{
					found = true;
					cout << "Enter the pin for verification: " << endl;
					cin >> temp_pin;

					if(ptr[i]->get_pin(temp_pin)) 
					{
						cout << "Enter the account number to which you want to transfer money: " << endl;
						cin >> temp_accno;
						
						bool f = false;
						for(int j = 0; j < count; j++)
						{
							if(ptr[j]->get_account(temp_accno)) 
							{
								f = true;
								cout << "Enter the amount to be transferred: " << endl;
								cin >> temp_Amount;

								if(temp_Amount > ptr[i]->get_balance()) 
								{
									cout << "Invalid transaction amount (Insufficient Balance)" << endl;
								}
								else if (temp_Amount <= 0)
								{
									cout << "Invalid amount. Enter a positive value." << endl;
								}
								else
								{
									ptr[j]->transfer_add(temp_Amount);
									ptr[i]->transfer_minus(temp_Amount);
									
									cout << "From : " << ptr[i]->get_name() << endl;
									cout << "To   : " << ptr[j]->get_name() << endl;
									cout << "Amount : " << temp_Amount << endl;
									cout << "Successfully transferred !" << endl;
								}
								break;
							}
						}

						if(!f)
						{
							cout << "Invalid receiver account number" << endl;
						}
					}
					else
					{
						cout << "Invalid pin" << endl;
					}
					break; // Exit sender search loop
				}
			}

			if(!found)
			{
				cout << "Invalid: your account number not found" << endl;
			}
			break;
		}
		
		case 3:
		{
		     if(count==0)
		    {
		        cout<<"Pls make an account first "<<endl;
		        break;
		    }
			float amount;
			cout<<"Enter the account number from which you need to withdraw money"<<endl;
			cin>>temp_accno;
			found=false;
			for(int i =0; i<count ; i++)
			{
				if(ptr[i]->get_account(temp_accno))
				{
				    found=true;
					cout<<"Enter the pin for verification the transaction"<<endl;
					cin>>temp_pin;
					if(ptr[i]->get_pin(temp_pin))
					{
						cout<<"Enter the amount to be withdrawed"<<endl;
						cin>>amount;
						if(temp_Amount>ptr[i]->get_balance())
						{
							cout<<"Invalid transaction amount "<<endl;
							break;
						}
						else
						{
							ptr[i]->transfer_minus( amount);
						}
					}
					else
					{
						cout<<"Invalid pin"<<endl;
						break;
					}
				}
			}
			cout<<"Succesfully withdrawed money!!"<<endl;
			if(!found)
			{
				cout<<"Invalid account number"<<endl;
				break;
			}
			break;
		}
		case 4:
		{
		     if(count==0)
		    {
		        cout<<"Pls make an account first "<<endl;
		        break;
		    }
			float amount;
			cout<<"Enter the account number to which you need to deposit money "<<endl;
			cin>>temp_accno;
			found=false;
			for(int i =0; i<count ; i++)
			{
				if(ptr[i]->get_account(temp_accno))
				{
				    found=true;
					cout<<"Enter the pin for verification the transaction"<<endl;
					cin>>temp_pin;
					if(ptr[i]->get_pin(temp_pin))
					{
						cout<<"Enter the amount to be deposit"<<endl;
						cin>>amount;
						if(temp_Amount>=0)
						{
							cout<<"Invalid transaction amount "<<endl;
							break;
						}
						else
						{
							ptr[i]->transfer_add( amount);
						}
					} else
					{
						cout<<"Invalid PIN"<<endl;
						break;
					}
				}
			}
			cout<<"Succesfully deposited money!!"<<endl;
			if(!found)
			{
				cout<<"Invalid account number"<<endl;
				break;
			}
			break;
		}
		case 5:
		{
		     if(count==0)
		    {
		        cout<<"Pls make an account first "<<endl;
		        break;
		    }
			cout<<"Enter the account number to which you need to change details "<<endl;
			cin>>temp_accno;
			found=false;
			for(int i =0; i<count ; i++)
			{
				if(ptr[i]->get_account(temp_accno))
				{
				    found=true;
					string n;
					float b;
					int p, a;
					cout<<"Enter the name of the person "<<endl;
					cin.ignore();
					getline(cin, n);
					cout<<"Enter the account number "<<endl;
					cin>>a;
					cout<<"Enter the balance you want to keep in your account "<<endl;
					cin>>b;
					delete ptr[i];  // free old object
					ptr[i] = new bank(n, a, b);

				}
			}
			cout<<"Succesfully stored"<<endl;
			if(!found)
			{
				cout<<"Invalid account number"<<endl;
				break;
			}
			break;
		}
		case 6:
		{
			cout<<"The total number of the accounts in the bank are "<<count<<endl;
			break;
		}
		case 7:
		{
		     if(count==0)
		    {
		        cout<<"Pls make an account first "<<endl;
		        break;
		    }
			cout<<"Enter the account number to which you need to deposit money "<<endl;
			cin>>temp_accno;
			found=false;
			for(int i =0; i<count ; i++)
			{
				if(ptr[i]->get_account(temp_accno))
				{
				    found=true;
				    ptr[i]->putdata();
				}
			}
			if(!found)
			{
			    cout<<"Invalid account number"<<endl;
			}
		}
		case 8:
		{
			cout<<"Exiting"<<endl;
			break;
		}
		
		default:
		{
			cout<<"Invalid choice"<<endl;
			break;
		}
		}
	} while(choice!=7);
	for(int i = 0; i < count; i++) 
	{
	    delete ptr[i];
	}
	return 0;
}