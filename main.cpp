#include <iostream>
#include <fstream>
using namespace std;
int flag = 0, ch; // checking admin details
float salary, pf;
long long int mobile_number;
string line;
// FILE MAGMENT SYSTEM

ofstream write_data;
ifstream read_data;

// Admin In Emp show Details And Add Function
void show_emp_details();
void add_emp_details();
void search_emp();
void delete_emp_details();
// Admin In Customer Details And other Function

void show_all_customer_data();
void update_customer_data();

// Admin Main Function Part
void admin_check_details();
void show_admin_details_menu();

class admin
{
private:
    string username = "Admini";
    int password = 1234;

public:
    string user_name = username;
    int pass_word = password;
    void admin_menu()
    {
        cout << "\n ==== WELCOME  TO  ADMIN  MENU ====";
        cout << "\n  1. Add Employee ";
        cout << "\n  2. See All Employee Details ";
        cout << "\n  3. Search Employee ";
        cout << "\n  4. Delete Employee";
        cout << "\n  5. See All Customer Details ";
        cout << "\n  6. Update Customer Data";
        cout << "\n  7. See The Last Year Financial Report";
        cout << "\n  8. Opning Account Public ";
        cout << "\n  9. Opning Account Private ";
        cout << "\n  10. Fund Details"; // bija 3 menu baki che banavana 1 report and 2 total 3.Profit And Lost
        cout << "\n  11. Logout";
    }
};
class customer
{
public:
    int customer_id;
    string customer_name;

    void add_customer_data()
    {
        write_data.open("customer.txt", ios::app);

        cout << "\n Enter Your Customer Id ";
        cin >> customer_id;

        cout << "\n Enter Your Customer Full Name ";
        cin.ignore();
        getline(cin, customer_name);

        write_data << "Customer Id = " << customer_id << endl;
        write_data << "Customer Name = " << customer_name << endl;

        write_data.close();
    }
};
class emp
{
};
void main_menu()
{
    cout << "\n WELCOME TO BANK OF BARODA";
    cout << "\n       1. Admin ";
    cout << "\n       2. Employee";
    cout << "\n       3. Customer ";
    cout << "\n       4. Exit...";
}

int main()
{

    int ch, ch2;

    do
    {
        main_menu();
        cout << "\n Enter Your Choice ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            system("cls");
            show_admin_details_menu();
            break;

        default:
            cout << "\n Invalide Choice ";
            break;
        }

    } while (ch != 4);

    return 0;
}

// It Is A Admin Part

void admin_check_details()
{

    admin a1;
    string user_n;
    int pas;

    cout << "\n Enter Admin Name";
    cin >> user_n;
    cout << "\n Enter Admin Password";
    cin >> pas;

    if (a1.user_name == user_n && a1.pass_word == pas)
    {
        flag = 1;
    }
    else
    {
        cout << "\n Getlost....";
        return;
    }
}

void show_admin_details_menu()
{
    admin a1;
    customer c1;
    admin_check_details();

    if (flag == 1)
    {

        do
        {

            a1.admin_menu();

            cout << "\n Enter Your Choice ";
            cin >> ch;

            switch (ch)
            {

            case 1:
                system("cls");
                add_emp_details();
                break;

            case 2:
                system("cls");
                show_emp_details();
                break;

            case 3:
                system("cls");
                search_emp();
                break;
            case 4:
                system("cls");
                show_all_customer_data();
                break;
            case 5:
                system("cls");
                delete_emp_details();
                break;
            case 6:
                system("cls");
                c1.add_customer_data();
                break;
            case 7:
                system("cls");
                update_customer_data();
                break;
            case 11:
                system("cls");
                cout << "\n BACK TO MAIN MENU ";
                break;
            default:
                cout << "\n Invalide Choice ";
                break;
            }
        } while (ch != 11);
    }
    else
    {
        cout << "\n GetLost...";
        return;
    }
}

void show_emp_details()
{

    admin_check_details();
    int ch;
    string line; // read each each line in file

    read_data.open("emp.txt");

    if (!read_data)
    {
        cout << "\n File Not Found!";
        return;
    }

    if (flag == 1)
    {

        while (getline(read_data, line))
        {
            cout << "\n " << line << endl;
        }
        read_data.close();
    }
    else
    {
        cout << " Get Lost..";
    }
}

void add_emp_details()
{
    admin_check_details();

    write_data.open("emp.txt", ios::app);

    int emp_id;
    string full_name;

    if (!write_data)
    {
        cout << "\n File Not Found!";
        return;
    }

    if (flag == 1)
    {

        cout << "\n Enter Emplooye Id ";
        cin >> emp_id;

        cin.ignore();
        cout << "\n Enter Emplooye Full Name ";
        getline(cin, full_name);

        cout << "\n Enter Emplooye Salary ";
        cin >> salary;

        cout << "\n Enter Emplooye PF (Provident Fund)";
        cin >> pf;

        cout << "\n Enter Emplooye Mobile Number ";
        cin >> mobile_number;

        write_data << "Emplooye ID = " << emp_id << endl;
        write_data << "Emplooye Name = " << full_name << endl;
        write_data << "Emplooye Salary = " << salary << endl;
        write_data << "Emplooye PF(Provident Fund) = " << pf << endl;

        if (mobile_number < 1000000000 || mobile_number > 9999999999)
        {
            cout << "\n Wrong Number Entered By The User";
            cout << "\n Enter Emplooye Mobile Number ";
            cin >> mobile_number;
        }
        else
        {
            write_data << "Emplooye Mobile Number = " << mobile_number << endl;
        }

        write_data.close();
    }
    else
    {
        cout << "\n Getlost...";
    }
}
void search_emp()
{
    admin_check_details();

    int search_id, emp_id;
    string line, full_name, salary, pf;
    bool found = false;
    long long int mobile_number;
    if (flag == 1)
    {
        read_data.open("emp.txt", ios::in);

        if (!read_data)
        {
            cout << "\n File Not Found!";
            return;
        }
        cout << "\n Enter Employee ID To Search: ";
        cin >> search_id;
        while (getline(read_data, line))
        {

            if (line.find("Emplooye ID = ") != string::npos) // the Emplooye ID is Found Than Goto Under If
            {
                emp_id = stoi(line.substr(line.find("=") + 1));
                // this code convert the strin data into integer data
                // stoi convert a string value into interger
                // line.substr is distribut the part after the = part
                // and add 1 to move the pointer Emp Id = to 1001
                getline(read_data, full_name);
                getline(read_data, salary);
                getline(read_data, pf);
                // getline(read_data, mobile_number);
                if (emp_id == search_id)
                {
                    cout << "\n======== Employee Found Data =========" << endl;
                    cout << line << endl;
                    cout << full_name << endl;
                    cout << salary << endl;
                    cout << pf << endl;
                    cout << "\n ========================================";
                    found = true;
                    break;
                }
            }
        }

        read_data.close();

        if (found == false)
        {
            cout << "\n Data Not Found In The Data Base";
        }
    }
    else
    {
        cout << "\n Getlost...";
    }
}
void delete_emp_details()
{

    read_data.open("emp.txt", ios::in);
    ofstream temp_file;

    temp_file.open("temp.txt");

    int search_id, emp_id;
    string line, full_name, salary, pf;
    bool found = false;

    cout << "\n Enter Your Emplooye Id You Want To Deleted It ";
    cin >> search_id;

    while (getline(read_data, line))
    {
        if (line.find("Emplooye ID = ") != string::npos)
        {
            emp_id = stoi(line.substr(line.find("=") + 1));
            getline(read_data, full_name);
            getline(read_data, salary);
            getline(read_data, pf);

            if (search_id == emp_id)
            {
                cout << "\n Emplooy Data Deleted Sucssesfully";
            }
            else
            {
                temp_file << emp_id << endl;
                temp_file << full_name << endl;
                temp_file << salary << endl;
                temp_file << pf << endl;
            }
        }
    }

    temp_file.close();
    read_data.close();
    remove("emp.txt");
    rename("temp.txt", "emp.txt");
}
// Admin In Customer Part

void show_all_customer_data()
{

    admin_check_details();

    if (flag == 1)
    {
        read_data.open("customer.txt", ios::in);

        cout << "\n====== ALL CUSTOMER DATA ====== " << endl;
        while (getline(read_data, line))
        {
            cout << line << endl;
        }
        cout << "\n ===============================";
    }
    else
    {
        cout << "\n Get lost.....";
    }
}

void update_customer_data()
{
    customer c1;
    read_data.open("customer.txt", ios::in);
    write_data.open("customer_update.txt", ios::app);
    int customer_id, cus_id, f = 1, c_id;
    string name;

    cout << "\n Enter Your Customer Searching Id ";
    cin >> customer_id;

    while (getline(read_data, line))
    {
        if (line.find("Customer Id = ") != string::npos)
        {
            cus_id = stoi(line.substr(line.find("=") + 1));
            getline(read_data, name);

            if (cus_id == customer_id)
            {

                cout << "\n Updated Menu ";
                cout << "\n 1. Update Customer Id ";
                cout << "\n 2. Update Customer Name ";
                cout << "\n 3. Update Customer Mobile Number";

                cout << "\n Enter Your Choice";
                cin >> ch;

                switch (ch)
                {
                case 1:
                    cout << "\n Enter Customer Id ";
                    cin >> cus_id;
                    break;

                default:
                    cout << "\n Invalide Choice ";
                    break;
                }
            }
            else
            {
                f = 0;
            }
            write_data << "Customer Id = " << cus_id << endl;
            write_data << name << endl;
        }
    }

    if (f == 0)
    {
        cout << "\n Data Not Found";
    }
}