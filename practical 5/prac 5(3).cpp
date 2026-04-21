
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	fstream obj;
	int quantity;
	string name;
	float price;
	int choice=0;
	do
	{
		cout<<"Enter 1 for Adding item "<<endl;
		cout<<"Enter 2 for view all items and count "<<endl;
		cout<<"Enter 3 for search item by name "<<endl;
		cout<<"Enter 4 for deleting an item "<<endl;
		cout<<"Enter 5 for exit "<<endl;
		cin>>choice;

		switch(choice)
		{
		case 1:
		{
			cout<<"Enter the name of the item: "<<endl;
			cin.ignore();
			getline(cin,name);
			cout<<"Enter the quantity of the item :"<<endl;
			cin>>quantity;
			cout<<"Enter the price of the item : "<<endl;
			cin>>price;
			obj.open("example.txt", ios::app);
			obj<<name<<"  "<<quantity<<" "<<price<<endl;
			obj.seekg(0);
			obj.close();
			break;
		}
		case 2:
		{
		    int count=0;
			string temp;
			obj.open("example.txt",ios::in);
			while(getline(obj, temp))
			{
			    count++;
				stringstream ss(temp);
				string temp2;
				while(ss >> temp2)
				{
					cout<<temp2 <<" ";
				}
				cout<<endl;
			}
			cout<<"The total item are "<<count<<endl;
			obj.close();
			break;
		}
		case 3:
		{
			string n;
			cout<<"Enter the name of the item for search "<<endl;
			cin.ignore();
			getline(cin, n);
			obj.open("example.txt",ios::in);
			string name2;
			int q;
			float p;
			bool found= false;
			while(obj>>name2>>q>>p)
			{
				if(n==name2)
				{
					cout << "\n\tItem Found!\n";
					cout << "Name: " << name2 << endl;
					cout << "Quantity: " << q << endl;
					cout << "Price: " << p << endl;
					found = true;
					break;
				}
			}
			if(!found)
			{
			    cout<<"Item not found!!!"<<endl;
			}
			cout<<endl;
			obj.close();
			break;
		}
		case 4:
		{
		    string delete_string;
		    cin.ignore();
		    cout<<"Enter the name of the item you want to delete "<<endl;
		    getline(cin,delete_string);
		    bool found=false;
		    fstream temp;
		    obj.open("example.txt",ios::in);
		    temp.open("temp.txt",ios::out);
		    string n;
		    int q;
		    float p;
		    while(obj>>n>>q>>p)
		    {
		        if(n==delete_string)
		        {
		            found=true;
		            
		            continue;
		        }
		        temp<<n<<" "<<q<<" "<<p<<endl;
		    }
		    obj.close();
		    temp.close();
		    remove("example.txt");
		    rename("temp.txt", "example.txt");
		    if(found)
		    {
		        cout<<"Deleted succesfully "<<endl;
		    }else
		    {
		        cout<<"Item not found"<<endl;
		    }
			break;
		}
		case 5:
		{
		    cout<<"exiting!"<<endl;
		    break;
		}
		default:
		{
		    cout<<"Invalid!!"<<endl;
		    break;
		}
		}
	} while(choice!=5);

	return 0;
}
