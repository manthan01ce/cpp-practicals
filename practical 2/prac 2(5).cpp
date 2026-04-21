#include<iostream>
#include<math.h>
using namespace std;
class bank_loan {
	int id;
	string name;
	double total_amount;
	double annual_interest;
	int loan_tenure;


public:
	bank_loan()//it is not considered as getter function
	{
		id=00;
		name="Default name";
		total_amount=0.0;
		annual_interest=0.0;
		loan_tenure=00;
	}

	bank_loan(int temp_id, string n, float a, float i, int t)
	{
		id=temp_id;
		name=n;
		total_amount=a;
		annual_interest=i;
		loan_tenure=t;
	}
	void   display_details();
	bool   getid(int temp_id);
	void   calculate_emi();
	double get_amount();//getter function
	double get_interest();//getter function
	int    get_time();//getter function
	void   change_amount(int return_amount);
};



void bank_loan::change_amount(int return_amount)
{
	total_amount-=return_amount;
}


bool bank_loan::getid(int temp_id)
{
	return temp_id==id;
}


void bank_loan::display_details()
{
	cout<<"The name of the applicant  is "<<name<<endl;
	cout<<"The Amount left for paying is "<<total_amount<<endl;
	cout<<"The interest for this loan is "<<annual_interest<<endl;
	cout<<"The tenure for this loan   is "<<loan_tenure<<endl;
}


void bank_loan::calculate_emi()
{
	double R=annual_interest/(12.0*100.0);
	total_amount+=total_amount*R;
	
}

int main()
{
	bank_loan b[20];
	int choice,flag=0;

	do {
		cout<<"Enter 1 for the taking loan "<<endl<<"Enter 2 for depositing the taken loan "<<endl;
		cout<<"Enter 3 for seeing details about loan"<<endl<<"Enter 4 for the exit"<<endl;
		cin>>choice;

		switch(choice)
		{
		case 1: {
			int temp_id,t;
			float a,i;
			string n;
			cout<<"Enter the loan id "<<endl;
			cin>>temp_id;
			cout<<"Enter the name of the applicant "<<endl;
			cin.ignore();
			getline(cin, n);
			cout<<"Enter the amount of the loan needed "<<endl;
			cin>>a;
			cout<<"Enter the interest rate you prefer "<<endl;
			cin>>i;
			cout<<"Enter the tenure of the loan in months only "<<endl;
			cin>>t;

			b[flag]=bank_loan(temp_id,n,a,i,t);
			flag++;
			cout<<"Loan approvedd succesfully!!!"<<endl;
			break;
		}
		case 2: {
			if(flag==0)
			{
				cout<<"First take an loan"<<endl;
				break;
			}
			int return_amount = 0, temp_id = 0;
			cout<<"Enter the loan id for deposting amount "<<endl;
			cin>>temp_id;
			bool found=false;
			for(int i=0; i<flag; i++)
			{
				if(b[i].getid(temp_id))
				{
					cout<<"Enter the amount to be payed from pending amount"<<endl;
					cin>>return_amount;
			        b[i].calculate_emi();
					b[i].change_amount(return_amount);
					}
					found=true;
				}
			
			if(!found)
			{
				cout<<"Id not found"<<endl;
				break;
			}

			break;
		}
		case 3: {
			if(flag==0)
			{
				cout<<"First take an loan"<<endl;
				break;
			}
			int temp_id;
			cout<<"Enter the loan id for seeing details"<<endl;
			cin>>temp_id;
			bool found=false;
			for(int i=0; i<flag; i++)
			{
				if(b[i].getid(temp_id))
				{
					b[i].display_details();
					found=true;
				}
			}
			if(!found)
			{
				cout<<"Id not found"<<endl;
				break;
			}
			break;
		}
		case 4: {
		    cout<<"Thanks for visiting!!"<<endl;
			break;
		}
		default: {
		    cout<<"Invalid choice!!"<<endl;
			break;
		}
		}
		} while(choice!=4);
	
	return 0;
}