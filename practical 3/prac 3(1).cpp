#include<iostream>
using namespace std;
class employee
{
  string name;
  int ID;
  float basic_salary,bonus_amount;
  public:
  void putdata();
  bool get_id(int temp_id);
  employee(string n, int temp_id, float bs)
  {
      name=n;
      ID= temp_id;
      basic_salary=bs;
      bonus_amount=5000.0;
  }
  
  inline int total_salary()
  {
      return bonus_amount+basic_salary;
  }
  employee(string n, int temp_id, float bs, float ba)
  {
      name=n;
      ID= temp_id;
      basic_salary=bs;
      bonus_amount=ba;
  }
  employee()
  {
    ID=0;
    basic_salary=0.0;
    bonus_amount=0.0;
    name="Default";
  }
    
};

void employee::putdata()
{
    cout<<"The ID of the empolyee is "<<ID<<endl;
    cout<<"The name of the employee is "<<name<<endl;
    cout<<"The basic salary of the employee is "<<basic_salary<<endl;
    cout<<"The bonus amount of the employee is "<<bonus_amount<<endl;
    cout<<"The total salary of the employee is "<<total_salary()<<endl;
}

bool employee::get_id(int temp_id)
{
    return ID== temp_id;
}


int main()
{
    employee *p=NULL;
    int size=0;
    int temp_id=0;
    int choice=0;
    do{
        cout<<"Enter 1 for the new employee "<<endl<<"Enter 2 for seeing the details"<<endl<<"Enter 3 for exit"<<endl;
        cin>>choice;
        if(choice==1)
        {
            employee *temp_p= new employee[size+1];
            for( int i =0;  i<size;i++)
            {
                temp_p[i]=p[i];
            }
            float bs,ba;
            string n;
            int choice_2=0;
            cout<<"Enter 1 for regular employee or 2 for special employee"<<endl;
            cin>>choice_2;
            if(choice_2 != 1 && choice_2 != 2)
            {
                cout<<"Invalid choice "<<endl;
            }else{
            if(choice_2==1)
            {
            cout<<"Enter the name of the employee "<<endl;
            cin.ignore();
            getline(cin, n);
            cout<<"Enter the ID of the employee "<<endl;
            cin>>temp_id;
            cout<<"Enter the basic salary of the employee "<<endl;
            cin>>bs;
            temp_p[size]= employee(n,temp_id,bs);
            delete []p;
            p=temp_p;
            size++;
            }else
            {
                float bs;
            cout<<"Enter the name of the employee "<<endl;
            cin.ignore();
            getline(cin, n);
            cout<<"Enter the ID of the employee "<<endl;
            cin>>temp_id;
            cout<<"Enter the basic salary of the employee "<<endl;
            cin>>bs;
            cout<<"Enter the bonus amount of the employee "<<endl;
            cin>>ba;
            temp_p[size]= employee(n,temp_id,bs, ba);
            delete []p;
            p=temp_p;
            size++;
            }
            }
        }else if(choice==2)
        {
            cout<<"Enter the id of the employee for seeing details"<<endl;
            cin>>temp_id;
            bool  found=false;
            for( int i =0;i<size ;i++)
            {
                if(p[i].get_id(temp_id))
                {
                    p[i].putdata();
                    found=true;
                }
            }
            if(!found)
            {
                cout<<"The employee of this ID is not found!!"<<endl;
            }
        }else
        {
            cout<<"Invalid choice "<<endl;
        }
    }while(choice!=3);
    return 0;
}