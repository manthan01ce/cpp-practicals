#include<iostream>
using namespace std;
class library {
	int ID;
	string title;
	string author;
	int number_of_copies;

public:
	void new_book();
	void return_book(int temp_returnbook);
	void total_book();
	int get_ID();
	int get_copies();
	void change_copies(int temp_issuebook);
};


void library::total_book()
{
	cout<<"The name of the title of the book is :"<<title<<endl;
	cout<<"The author name is                   :"<<author<<endl;
	cout<<"The number of copis available is     :"<<number_of_copies<<endl;
	cout<<"The book ID number is                :"<<ID<<endl;

}
int library::get_copies()
{
	return number_of_copies;
}

void library::change_copies(int temp_issuebook)
{
	number_of_copies-=temp_issuebook;
}

int library::get_ID()
{
	return ID;
}
void library::new_book()
{
	cout<<"Enter the book ID number"<<endl;
	cin>>ID;
	cout<<"Enter the title of the book"<<endl;
	cin.ignore();
	getline(cin, title);
	cout<<"Enter the author name of the book"<<endl;
	cin.ignore();
	getline(cin, author);
	cout<<"Enter the total number of the copies available in the library"<<endl;
	cin>>number_of_copies;
	cout<<"Succesfully stored"<<endl;
}

void library::return_book(int temp_returnbook)
{
	number_of_copies+=temp_returnbook;
}

using namespace std;
int main()
{
	int issued_book=0;
	int flag=0,temp_issuebook=0,temp_returnbook=0;
	library book[20];
	int choice=0;
	do {
		cout<<"Enter 1 for the new book"<<endl<<"Enter 2 for issue a book"<<endl<<"Enter 3 for returning the book"<<endl;
		cout<<"Enter 4 for seeing details of the book in the library"<<endl<<"Enter 5 for exit"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
		{
			book[flag].new_book();
			flag++;
			break;
		}
		case 2:
		{
			int temp_id=0;
			cout<<"Enter the ID number of the book"<<endl;
			cin>>temp_id;
			bool found= false;
			for(int i=0; i<flag; i++)
			{
				if(book[i].get_ID()==temp_id)
				{
					cout<<"Enter the number of the book to be issue"<<endl;
					cin>>temp_issuebook;
					issued_book=temp_issuebook;
					if(temp_issuebook>book[i].get_copies())
					{
						cout<<"Out of stock "<<endl;
						found=true;
						break;
					} else {
						book[i].change_copies(temp_issuebook);
						cout<<"The "<<temp_issuebook<<" books are issued."<<endl;
						found=true;
						break;
					}
				}
			}
			if(!found)
			{
				cout<<"The book of that ID is not available"<<endl;
			}
			break;
		}
		case 3:
		{
			int temp_id;
			if(temp_issuebook==0 or temp_returnbook>=temp_issuebook)
			{
				cout<<"First issue the book"<<endl;
				break;
			}

			cout<<"Enter the ID number of the book"<<endl;
			cin>>temp_id;
			bool found= false;
			for(int i=0; i<flag; i++)
			{
				if(book[i].get_ID()==temp_id)
				{
					cout<<"Enter the number of the book to be returned "<<endl;
					cin>>temp_returnbook;
					if(temp_returnbook>issued_book)
					{
						cout<<"You can return the book that are issued not more than that"<<endl;
					}
					book[i].return_book(temp_returnbook);
					found=true;
					break;
				}
			}
			if(!found)
			{
				cout<<"The book of that ID is not available"<<endl;
			}
		}
		break;

		case 4:
		{
			int temp_id=0;
			cout<<"Enter the book ID for seeing details"<<endl;
			cin>>temp_id;
			bool found= false;
			for(int i=0; i<flag; i++)
			{
				if(book[i].get_ID()==temp_id)
				{
					book[i].total_book();
					found=true;

				}
			}
			if(!found)
			{
				cout<<"The book of that ID is not available"<<endl;
			}
			break;
		}
		case 5: {
			cout<<"Exiting"<<endl;
			break;
		}
		default :
			cout<<"Invalid choice "<<endl;
			break;

		}
	} while(choice!=5);

	return 0;
}