#include<iostream>
using namespace std;
class product
{
	int unique_id;
	string name;
	float price;
	int quantity;

public:
	product()
	{
		unique_id=000;
		name="Default constructor";
		price=000;
		quantity=000;

	}

	product(int id, string temp_name, float temp_price,int temp_quantity)
	{
		unique_id=id;
		name=temp_name;
		price=temp_price;
		quantity=temp_quantity;
	}
	void getdata();
	void putdata();
	bool get_id(int temp_id);
	void change_data();
	void add_stock(int temp_stock);
	void sell_stock(int temp_stock);
};

void product::add_stock(int temp_stock)
{
	quantity+=temp_stock;
}
void product::sell_stock(int temp_stock)
{
	if(quantity<temp_stock)
	{
		cout<<"Invalid quantity not available"<<endl;
		return;
	}
	quantity-=temp_stock;
}
void product::change_data()
{
	int choose=0;
	cout<<"Enter 1 for changing the name"<<endl;
	cout<<"Enter 2 for changing the price"<<endl;
	cin>>choose;
	if(choose==1)
	{
		int temp_temp_name;
		cout<<"Enter the new name of the product"<<endl;
		getline(cin,name);
	} else if(choose==2)
	{
		cout<<"Enter the new price of the product"<<endl;
		cin>>price;
	}
}
bool product::get_id(int temp_id)
{
	return unique_id==temp_id;
}
void product::putdata()
{
	cout<<"The name of the item is "<<name<<endl;
	cout<<"The price of the item is "<<price<<endl;
	cout<<"The quantity of the item is "<<quantity<<endl;
	cout<<"The Unique ID number of the item is "<<unique_id;
}
void product::getdata()
{
	int temp_id,temp_quantity;
	float temp_price;
	string temp_name;
	cout<<"Enter the unique ID of the item"<<endl;
	cin>>temp_id;
	cout<<"Enter the name of the item"<<endl;
	getline(cin, temp_name);
	cout<<"Enter the price of the item"<<endl;
	cin>>temp_price;
	cout<<"Enter the quantity of the item"<<endl;
	cin>>temp_quantity;
	cout<<"Parametered consturctor called"<<endl;
}

int main()
{
	int choice=0;
	product p[20];
	p[0] = product(101, "Milk", 2.50, 10);
	p[1] = product(102, "Bread", 1.20, 20);
	int flag=2;
	cout<<"\t\tWelcome to the store"<<endl;
	do {
		cout<<"Enter 1 for the adding new product"<<endl<<"Enter 2 for the changing the detail"<<endl;
		cout<<"Enter 3 for new stock "<<endl<<"enter 4 to change the quantity after selling"<<endl;
		cout<<"Enter 5 for the seeing the details of the item"<<endl<<"Enter 6 for the exiting "<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1: {
			if(flag>20)
			{
				cout<<"Insufficient space"<<endl;
			}
			int temp_id,temp_quantity;
			float temp_price;
			string temp_name;
			cout<<"Enter the unique ID of the item"<<endl;
			cin>>temp_id;
			cout<<"Enter the name of the item"<<endl;
			cin.ignore();
			getline(cin, temp_name);
			cout<<"Enter the price of the item"<<endl;
			cin>>temp_price;
			cout<<"Enter the quantity of the item"<<endl;
			cin>>temp_quantity;

			p[flag]=product(temp_id,temp_name,temp_price,temp_quantity);
			flag++;
			break;
		}
		case 2: {
			int temp_id;
			cout<<"Enter the id for the changing the item details"<<endl;
			cin>>temp_id;
			bool found=false;
			for(int i=0; i<flag; i++)
			{
				if(p[i].get_id(temp_id))
				{
					p[i].change_data();
					cout<<"Data changed succesully"<<endl;
					found=true;
					break;
				}
			}
			if(!found)
			{
				cout<<"Invalid ID not found"<<endl;
				break;
			}
			break;
		}

		case 3:
		{
			int temp_id;
			cout<<"Enter the id of the item for adding stock"<<endl;
			cin>>temp_id;
			bool found=false;
			for(int i=0; i<flag; i++)
			{
				if(p[i].get_id(temp_id))
				{
					int temp_stock;
					cout<<"Enter the new stock to be added"<<endl;
					cin>>temp_stock;
					p[i].add_stock(temp_stock);
					cout<<"Added succesully"<<endl;
					found=true;
					break;
				}
			}
			if(!found)
			{
				cout<<"Invalid ID not found"<<endl;
				break;
			}
			break;
		}
		case 4:
		{
			int temp_id;
			cout<<"Enter the id for selling the stock detial"<<endl;
			cin>>temp_id;
			bool found=false;
			for(int i=0; i<flag; i++)
			{
				if(p[i].get_id(temp_id))
				{
					int temp_stock;
					cout<<"Enter the new stock that is sold"<<endl;
					cin>>temp_stock;
					p[i].sell_stock(temp_stock);

					found=true;
					break;
				}
			}
			if(!found)
			{
				cout<<"Invalid ID not found"<<endl;
				break;
			}
			break;

		}

		case 5:
		{
			int temp_id;
			cout<<"Enter the id for the seeing the details"<<endl;
			cin>>temp_id;
			bool found=false;
			for(int i=0; i<flag; i++)
			{
				if(p[i].get_id(temp_id))
				{
					p[i].putdata();
					found=true;
					break;
				}
			}
			if(!found)
			{
				cout<<"Invalid ID not found"<<endl;
				break;
			}
			break;
		}
		case 6:
		{
			cout<<"exiting"<<endl;
			break;
		}

		}
	} while(choice!=6);
	return 0;
}