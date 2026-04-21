#include<iostream>
#include<vector>
using namespace std;
vector<int>accNumbers;
class accounts
{
	string name;
	long long acc_no;
	long long balance;
	int pin;
	bool interest_applied;
	int wrong_pin_count;
	bool account_locked;
public:
	accounts()
	{
		name="Default";
		acc_no=0;
		balance=0.0;
		pin=0000;
		interest_applied=false;
		wrong_pin_count=0;
		account_locked=false;
	}
	bool isUnique(int accNo, vector<int> &accNumbers);
	bool verify_lock();
	void change_pin();
	void get_info();
	void put_info();
	void withdraw();
	void deposit();
	void calculate_interest();
	int get_number();
};


bool accounts::isUnique(int accNo, vector<int> &accNumbers)
{
	for(int num : accNumbers)
	{
		if(num == accNo)
		{
			return false;
		}
	}
	return true;
}


void accounts::change_pin()
{
	int new_pin;
	cout<<"Enter the new pin "<<endl;
	cin>>new_pin;
	if(new_pin==pin)
	{
		cout<<"You already have this pin"<<endl;
		return ;
	}
	pin=new_pin;
	cout<<"succesfully changed"<<endl;
}
void accounts::calculate_interest()
{
	if(interest_applied)
	{
		return;
	}
	int rate;
	if(balance>=100000)
	{
		rate=12;
	} else if(balance>=70000)
	{
		rate=10;
	} else if(balance>=50000)
	{
		rate=8;
	} else
	{
		rate=6;
	}

	int interest_amount= (balance*rate)/100;
	balance+=interest_amount;
	interest_applied=true;
}
void accounts::deposit()
{
	int amount;

	cout<<"Enter the amount to be deposited in the account "<<endl;
	cin>>amount;
	if(amount<=0)
	{
		cout<<"Error!!! pls enter the valid amount"<<endl;
		return;
	}
	balance+=amount;
	cout<<"succesfully deposited"<<endl;
}
void accounts::withdraw()
{
	int amount;

	cout<<"Enter the amount to be withdraw  from account "<<endl;
	cin>>amount;
	if(amount<=0)
	{
		cout<<"Enter the valid amount"<<endl;
		return;
	}
	if(amount>balance)
	{
		cout<<"Insufficient amount in account "<<endl;
		return;
	}
	balance-=amount;
	cout<<"succesfully withdrawed"<<endl;
}
int accounts::get_number()
{
	return acc_no;
}


bool accounts::verify_lock()
{
	int temp_pin;

	while(wrong_pin_count < 3)
	{
		cout<<"Enter PIN: ";
		cin>>temp_pin;

		if(temp_pin == pin)
		{
			wrong_pin_count = 0;
			return true;
		}
		else
		{
			wrong_pin_count++;
			cout<<"Incorrect PIN\n";
			cout<<"Attempts left: "<<3 - wrong_pin_count<<endl;
		}
	}

	account_locked = true;
	cout<<"Account locked after 3 incorrect attempts\n";

	int choice;
	cout<<"Press 1 to unlock by paying Rs 300\n";
	cout<<"Press 2 to exit\n";
	cin>>choice;

	if(choice == 1)
	{
		balance -= 300;
		account_locked = false;
		wrong_pin_count = 0;
		cout<<"Account unlocked\n";
	}

	return false;
}
void accounts::get_info()
{
	cout<<"Enter the name "<<endl;
	cin.ignore();
	getline(cin,name);
	cout<<"Enter the account number  "<<endl;
	cin>>acc_no;

	do
	{
		cout << "Enter Account Number: ";
		cin >> acc_no;

		if(!isUnique(acc_no, accNumbers))
		{
			cout << "Account number already exists. Enter another.\n";
		}

	} while(!isUnique(acc_no, accNumbers));

	accNumbers.push_back(acc_no);
	cout<<"Enter the PIN for account "<<endl;
	cin>>pin;
	cout<<"Enter the intial balance  "<<endl;
	cin>>balance;
	interest_applied=false;
	account_locked  =false;
}


void accounts::put_info()
{
	calculate_interest();
	cout<<"Account no : "<<acc_no<<endl;
	cout<<"Name       : "<<name<<endl;
	cout<<"balance    : "<<balance<<endl;
}
int main()
{
	vector<accounts>bank_account;

	int choice=0;
	do {
		cout<<"Enter 1 for new account     "<<endl;
		cout<<"Enter 2 for withdrawal      "<<endl;
		cout<<"Enter 3 for deposit         "<<endl;
		cout<<"Enter 4 for checking balance"<<endl;
		cout<<"Enter 5 for changing pin    "<<endl;
		cout<<"Enter 6 for closing account "<<endl;
		cout<<"Enter 7 for exit            "<<endl;
		cin>>choice;
		bool is_there=false;
		long long temp_id;
		int temp_pin;
		switch(choice)
		{
		case 1:
		{
			accounts a1;//class variable
			a1.get_info();
			bank_account.push_back(a1);
			cout<<"Bank account created succesfully"<<endl;
			break;
		}

		case 2:
		{
			cout<<"Enter the account number"<<endl;
			cin>>temp_id;
			is_there=false;
			for(auto &a1: bank_account)
			{
				if(a1.get_number()==temp_id)
				{
					if(a1.verify_lock())
					{
						is_there=true;
						a1.withdraw();
					}
				}
			}
			break;
		}

		case 3:
		{
			cout<<"Enter the account number"<<endl;
			cin>>temp_id;
			is_there=false;
			for(auto &a1: bank_account)
			{
				if(a1.get_number()==temp_id)
				{
					if(a1.verify_lock())
					{
						is_there=true;
						a1.deposit();
					}
				}
			}
			if(!is_there)
			{
				cout<<"Account not found!!"<<endl;
			}
			break;
		}

		case 4:
		{
			cout<<"Enter the account number to be viewed for details"<<endl;
			cin>>temp_id;
			is_there=false;
			for(auto &a1: bank_account)
			{
				if(a1.get_number()==temp_id)
				{
					if(a1.verify_lock())
					{
						is_there=true;
						a1.put_info();
					}
				}
			}
			if(!is_there)
			{
				cout<<"Account not found!!"<<endl;
			}
			break;
		}

		case 5:
		{

			cout<<"Enter the account number "<<endl;
			cin>>temp_id;
			is_there=false;
			for(auto &a1: bank_account)
			{
				if(a1.get_number()==temp_id)
				{
					if(a1.verify_lock())
					{
						is_there=true;
						a1.change_pin();
					}
				}
			}
			if(!is_there)
			{
				cout<<"Account not found!!"<<endl;
			}
			break;
		}

		case 6: {

			cout<<"Enter the account number"<<endl;
			cin>>temp_id;
			is_there=false;
			for(int i =0; i<bank_account.size(); i++)
			{
				if(bank_account[i].get_number()==temp_id)
				{
					if(bank_account[i].verify_lock())
					{
						is_there=true;
						bank_account.erase(bank_account.begin()+i);
						cout<<"succesfully deleted"<<endl;
					}
				}
			}
			if(!is_there)
			{
				cout<<"Account not found!!"<<endl;
			}
			break;
		}
		case 7:
		{
			break;
		}
		default:
		{
			cout<<"Invalid choice"<<endl;
			break;
		}

		}

	} while(choice!=7);
	return 0;
}