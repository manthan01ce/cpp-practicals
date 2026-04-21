#include<iostream>
#include<vector>
#include<iomanip>
#include<limits>
using namespace std;

class fuel
{
    string type;

public:
    fuel(string t)
    {
        type = t;
    }

    string get_s()
    {
        return type;
    }

    void putdata();
};

void fuel::putdata()
{
    cout << "The type of fuel car has is " << type << endl;
}

class brand
{
    string model;

public:
    brand(string m)
    {
        model = m;
    }

    string get_m()
    {
        return model;
    }

    void p_data();
};

void brand::p_data()
{
    cout << "The model of the car is " << model << endl;
}

class car : public brand, public fuel
{
public:
    car(string m, string t) : brand(m), fuel(t) {}

    void pp_data();
};

void car::pp_data()
{
    putdata();
    p_data();
}

int main()
{
    vector<car> count;
    int choice = 0;

    do
    {
        cout << "\nEnter 1 for adding the detail of the car " << endl;
        cout << "Enter 2 for seeing the details " << endl;
        cout << "Enter 3 for searching the car by brand name" << endl;
        cout << "Enter 4 for seeing the total number of car " << endl;
        cout << "Enter 5 for exit " << endl;

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            string t, m;

            cout << "Enter the type of fuel (Petrol/Diesel/Cng): ";
            getline(cin, t);

            cout << "Enter the model name of the car: ";
            getline(cin, m);

            car c(m, t);
            count.push_back(c);

            break;
        }

        case 2:
        {
            cout << "---------------------------------\n";
            cout << setw(10) << "Type" << setw(20) << "Model\n";
            cout << "---------------------------------\n";

            for (int i = 0; i < count.size(); i++)
            {
                cout << setw(10) << count[i].get_s()
                     << setw(20) << count[i].get_m() << endl;
            }

            cout << "---------------------------------\n";
            break;
        }

        case 3:
        {
            string search;

            cout << "Enter the model name of the car: ";
            getline(cin, search);

            bool found = false;

            for (int i = 0; i < count.size(); i++)
            {
                if (count[i].get_m() == search)
                {
                    found = true;
                    cout << "\nCar found:\n";
                    count[i].pp_data();
                    break;
                }
            }

            if (!found)
            {
                cout << "No such car exists\n";
            }

            break;
        }

        case 4:
        {
            cout << "Total number of cars: " << count.size() << endl;
            break;
        }

        case 5:
        {
            cout << "Exiting... Thank you!\n";
            break;
        }

        default:
        {
            cout << "Invalid choice\n";
            break;
        }
        }

    } while (choice != 5);

    return 0;
}