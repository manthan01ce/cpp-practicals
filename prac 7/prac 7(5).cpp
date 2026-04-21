#include<iostream>
using namespace std;
class gradingsystem
{
    protected:
	int marks;
public:
	void get(int m)
	{
		this->marks=m;
	}
	virtual void computeGrade()=0;
};



class undergraduate: public gradingsystem
{
public:
	void computeGrade() {
		if (marks >= 90)
		{
			cout << "Undergraduate Grade: A" << endl;
		}
		else if (marks >= 75)
		{
			cout << "Undergraduate Grade: B" << endl;
		}
		else if (marks >= 60)
		{
			cout << "Undergraduate Grade: C" << endl;
		}
		else
		{
			cout << "Undergraduate Grade: D" << endl;
		}
	}
	};



	class postgraduate:public gradingsystem
	{
	public:
		void computeGrade() {
			if (marks >= 90)
			{
				cout << "Postgraduate Grade: A" << endl;
			}
			else if (marks >= 80)
			{
				cout << "Postgraduate Grade: B" << endl;
			}
			else if (marks >= 70)
			{
				cout << "Postgraduate Grade: C" << endl;
			}
			else
			{
				cout << "Postgraduate: Fail" << endl;
			}
	}
	};
		int main()
		{
            gradingsystem *ptr;
            undergraduate u1;
            postgraduate p1;
            
            ptr=&u1;
            ptr->get(99);
            ptr->computeGrade();
            
            
            ptr=&p1;
            ptr->get(89);
            ptr->computeGrade();
			return 0;
		}

	