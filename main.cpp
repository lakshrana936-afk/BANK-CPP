#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int flag = 0, ch;
float salary, pf;
long long int mobile_number;
string line, line1;

// GLOBAL VARIABLE DECLARATION

emp e1;
admin a1;
customer c1;

// FILE MANAGMENT PART
ofstream write_data;
ifstream read_data;

int pin, cus_id;
float amount;
string full_name, status;
long long int account_number;

float money, total = 0, orignal_fund;
string place;

void show_all_customer_data();
void update_customer_data();
void emp_menu();
void emp_switch_part();
void switch_part_of_customer();
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
        cout << "\n  8. Fund Details"; // bija 3 menu baki che banavana 1 report and 2 total 3.Profit And Lost
        cout << "\n  9. Logout";
    }

    void finanacial_menu()
    {
        cout << "\n = = = = MENU OF FINANACE = = = =";
        cout << "\n         1. Add Fund ";
        cout << "\n         2. See Total Fund ";
        cout << "\n         3. Show Current Year Report";
        cout << "\n         4. See Profit And Lost ";
        cout << "\n         5. Back To Menu  ";
    }

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
            flag = 2;
        }
    }

    void show_emp_details();
    void add_emp_details();
    void search_emp();
    void delete_emp_details();
    void last_year_report();
    void financial_part();
    void add_fund();
    void see_total_fund();
    void report_of_current_year();
    void profit_loss();
};
class customer
{
public:
    void customer_field_menu()
    {
        cout << "\n = = = = WELCOME TO CUSTOMER MENU = = = = ";
        cout << "\n         1. Show My Account ";
        cout << "\n         2. Credit Money ";
        cout << "\n         3. Withrawal Money";
        cout << "\n         4. Logout ";
    }

    void show_my_details();

    void credit_amount();
    void withrawal_amount();
};
class emp
{
private:
    string name = "emp";
    int pin = 12345;

public:
    string n = name, nam;
    int p = pin, pas;
    bool flag = false;
    void emp_checking()
    {
        cout << "\n Enter Your User Name ";
        cin >> nam;
        cout << "\n Enter Your PIN ";
        cin >> pas;

        if (nam == n && p == pas)
        {
            flag = true;
        }
        else
        {
            cout << "\n Get Lost ... ";
        }
    }
    void add_customer_details();
    void search_customer_account();
    void delete_customer();
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
        case 2:
            system("cls");
            emp_switch_part();
            break;
        case 3:
            system("cls");
            switch_part_of_customer();
            break;
        default:
            cout << "\n Invalide Choice ";
            break;
        }

    } while (ch != 4);

    return 0;
}

// It Is A Admin Part

void show_admin_details_menu()
{
    admin a1;
    customer c1;
    a1.admin_check_details();

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
                a1.add_emp_details();
                break;

            case 2:
                system("cls");
                a1.show_emp_details();
                break;

            case 3:
                system("cls");
                a1.search_emp();
                break;
            case 4:
                system("cls");
                a1.delete_emp_details();

                break;
            case 5:
                system("cls");
                show_all_customer_data();
                break;
            case 6:
                system("cls");
                update_customer_data();
                break;
            case 7:
                system("cls");
                a1.last_year_report();
                break;
            case 8:
                system("cls");
                a1.financial_part();
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

void admin::show_emp_details()
{

    int ch;
    string line; // read each each line in file

    read_data.open("emp.txt", ios::in);

    if (!read_data)
    {
        cout << "\n File Not Found!";
        return;
    }

    while (getline(read_data, line))
    {
        cout << "\n " << line << endl;
    }

    read_data.close();
}

void admin::add_emp_details()
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
    }

    if (flag == 2)
    {
        cout << "\n Get lost........";
    }

    write_data.close();
}

void admin::search_emp()
{
    admin_check_details();

    int search_id, emp_id;
    string full_name, salary, pf, mobile_line;
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

        while (getline(read_data, line), getline(read_data, line1))
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
                getline(read_data, mobile_line);

                if (emp_id == search_id)
                {
                    cout << "\n= = = = Employee Found Data = = = =" << endl;

                    cout << line << endl;
                    cout << full_name << endl;
                    cout << salary << endl;
                    cout << pf << endl;
                    cout << mobile_line << endl;

                    cout << "\n = = = = = = = = = = = = = = = = = = = ";
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

    if (flag == 2)
    {
        cout << "\n get lost ......";
    }
}
void admin::delete_emp_details()
{

    read_data.open("emp.txt", ios::in);
    ofstream temp_file;

    temp_file.open("temp.txt", ios::app);

    int search_id, emp_id;
    string line, full_name, salary, pf, mobile_line;
    bool found = false;

    cout << "\n Enter Your Emplooye Id You Want To Deleted It ";
    cin >> search_id;

    if (!read_data || !temp_file)
    {
        cout << "File Is Not Open ";
        return;
    }

    if (flag == 1)
    {

        while (getline(read_data, line))
        {

            if (line.find("Emplooye ID = ") != string::npos) // the Emplooye ID is Found Than Goto Under If
            {

                emp_id = stoi(line.substr(line.find("=") + 1));

                getline(read_data, full_name);
                getline(read_data, salary);
                getline(read_data, pf);
                getline(read_data, mobile_line);

                if (search_id != emp_id)
                {
                    temp_file << line << endl;
                    temp_file << full_name << endl;
                    temp_file << salary << endl;
                    temp_file << pf << endl;
                    temp_file << mobile_line << endl;
                }
                else
                {
                    cout << "\n Emplooye Data Found " << endl;

                    cout << line << endl;
                    cout << full_name << endl;
                    cout << salary << endl;
                    cout << mobile_line << endl;

                    cout << "\n Data Deleted Successfully ";

                    found = true;
                }
            }
        }

        if (found == false)
        {
            cout << "\n Data Not Found In Data Base ";
        }

        temp_file.close();
        read_data.close();
        remove("emp.txt");
        rename("temp.txt", "emp.txt");
    }

    if (flag == 2)
    {
        cout << "\n Get Lost .....";
    }
}

// Admin In Customer Part

void show_all_customer_data()
{

    a1.admin_check_details();

    if (flag == 1)
    {
        read_data.open("customer.txt", ios::in);

        cout << "\n= = = = ALL CUSTOMER DATA = = = = " << endl;

        while (getline(read_data, line))
        {
            cout << line << endl;
        }
        cout << "\n = = = = = = = = = = = = = = = = = ";

        read_data.close();
    }

    if (flag == 2)
    {
        cout << "\n Get Lost .....";
    }
}

void update_customer_data()
{
    a1.admin_check_details();

    read_data.open("customer.txt", ios::in);
    write_data.open("customer_update.txt", ios::app);

    int customer_id, choice;
    long long int customer_ac_n, cus_id;
    string line, name, mobile_line, updatede_status, amount_line, status_line, pin_line;
    bool found = false;

    if (!read_data || !write_data)
    {
        cout << "\n File Not Found!";
        return;
    }

    if (flag == 1)
    {
        cout << "\n Enter Customer Account Number: ";
        cin >> customer_ac_n;

        while (getline(read_data, line))
        {
            if (line.find("Account Number = ") != string::npos)
            {
                cus_id = stoll(line.substr(line.find("=") + 1));

                getline(read_data, name);
                getline(read_data, amount_line);
                getline(read_data, mobile_line);
                getline(read_data, status_line);
                getline(read_data, pin_line);

                if (cus_id == customer_ac_n)
                {
                    found = true;

                    cout << "\n Customer Found!";
                    cout << "\n Account Number = " << cus_id;
                    cout << "\n " << name;
                    cout << "\n " << amount_line;
                    cout << "\n " << mobile_line;
                    cout << "\n " << status_line;
                    cout << "\n " << pin_line;

                    cout << "\n 1. Update Customer Name";
                    cout << "\n 2. Update Customer Mobile Number";
                    cout << "\n 3. Update Customer Account Status";
                    cout << "\n Enter Your Choice: ";
                    cin >> choice;

                    if (choice == 1)
                    {
                        cout << "\n Enter New Customer Name: ";
                        cin.ignore();
                        getline(cin, name);

                        name = "Customer Name = " + name;
                    }
                    else if (choice == 2)
                    {
                        cout << "\n Enter New Mobile Number: ";
                        cin >> mobile_number;

                        if (mobile_number >= 1000000000LL && mobile_number <= 9999999999LL)
                        {
                            mobile_line = "Customer Mobile Number = " + to_string(mobile_number);
                        }
                        else
                        {
                            cout << "\n Invalid Mobile Number!";
                        }
                    }

                    else if (choice == 3)
                    {
                        cout << "\n Enter The Updated Account Status (UnBlock , Block )";
                        cin >> status;

                        if (status == "Block" || status == "UnBlock")
                        {
                            updatede_status = "Customer Account Status = " + status;
                        }
                        else
                        {
                            cout << "\n User Entred Wrong Status ";
                        }
                    }
                    else
                    {
                        cout << "\n Invalid Choice!";
                    }
                }

                write_data << "Account Number = " << cus_id << endl;
                write_data << name << endl;
                write_data << amount_line << endl;
                write_data << mobile_line << endl;
                write_data << status_line << endl;
            }
        }

        read_data.close();
        write_data.close();

        remove("customer.txt");
        rename("customer_update.txt", "customer.txt");

        if (found)
        {
            cout << "\n Customer Data Saved In customer_update.txt";
        }
        else
        {
            cout << "\n Customer Not Found!";
        }
    }

    if (flag == 2)
    {
        cout << "\n Get Lost ..... ";
    }
}

// ADDING A CUSTOMER DETAILS

void emp::add_customer_details()
{
    e1.emp_checking();

    write_data.open("customer.txt", ios::app);

    if (!write_data)
    {
        cout << "\n File Not Open ";
        return;
    }

    if (flag == 1)
    {

        cout << "\n Enter Customer Account Number(10 Digit ) ";
        cin >> account_number;
        if (account_number < 1000000000 || account_number > 9999999999)
        {
            cout << "\n Enter Customer Account Number ";
            cin >> account_number;
        }
        else
        {
            write_data << "Account Number = " << account_number << endl;
        }
        cin.ignore();
        cout << "\n Enter Customer Full Name ";
        getline(cin, full_name);

        cout << "\n Enter Customer Mobile Number ";
        cin >> mobile_number;

        cout << "\n Enter Customer Amount ";
        cin >> amount;

        write_data << "Customer Name = " << full_name << endl;
        write_data << "Customer Amount = " << amount << endl;

        if (mobile_number < 1000000000 || mobile_number > 9999999999)
        {
            cout << "\n Wrong Number Entered By The User";
            cout << "\n Enter Emplooye Mobile Number ";
            cin >> mobile_number;
        }

        else
        {
            write_data << "Customer Mobile Number = " << mobile_number << endl;
        }

        cout << "\n Enter The Updated Account Status (UnBlock , Block )";
        cin >> status;

        if (status == "Block" || status == "UnBlock")
        {
            write_data << "Account Status = " << status << endl;
        }
        else
        {
            cout << "\n User Entred Wrong Status ";
        }

        cout << "\n Enter Your Transaction ";
        cin >> pin;

        write_data << "Customer Transaction PIN = " << pin << endl;

        write_data.close();
    }

    if (flag == 2)
    {
        cout << "\n Get Lost ....";
    }
}

void admin::last_year_report()
{
    admin_check_details();

    if (flag == 1)
    {

        cout << "\n";
        cout << "====================================================\n";
        cout << "              BANK OF BARODA\n";
        cout << "           FINANCIAL REPORT 2025-26\n";
        cout << "====================================================\n";
        cout << "\n              BANK SUMMARY\n";
        cout << "----------------------------------------------------\n";
        cout << "\n Total Customers " << setw(20) << ":" << setw(10) << 12700;
        cout << "\n Total Employees " << setw(20) << ":" << setw(10) << 500;
        cout << "\n Total Deposits  " << setw(20) << ":" << setw(4) << "RS." << setw(3) << 8500000;
        cout << "\n Total Withdeawals  " << setw(17) << ":" << setw(4) << "RS." << setw(3) << 4200000;
        cout << "\n Total Loans " << setw(24) << ":" << setw(4) << "RS." << setw(3) << 1250000;
        cout << "\n Total Interest Earned " << setw(14) << ":" << setw(4) << "RS." << setw(3) << 3500000;
        cout << "\n ";
        cout << "\n ";

        cout << "\n                PROFIT SUMMARY                 ";
        cout << "\n----------------------------------------------------";
        cout << "\n Total Income  " << setw(22) << ":" << setw(4) << "RS." << setw(3) << 500000.00;
        cout << "\n Total Expenses  " << setw(20) << ":" << setw(4) << "RS." << setw(3) << 180000.00;
        cout << "\n Net Profit   " << setw(23) << ":" << setw(4) << "RS." << setw(3) << 320000.00;
        cout << "\n----------------------------------------------------";
    }
    if (flag == 2)
    {
        cout << "\n Get Lost ......";
    }
}

void admin::financial_part()
{
    admin a1;

    do
    {
        a1.finanacial_menu();
        cout << "\n Enter Your Choice =>";
        cin >> ch;
        switch (ch)
        {
        case 1:
            system("cls");
            a1.add_fund();
            break;
        case 2:
            system("cls");
            a1.see_total_fund();
            break;
        case 3:
            system("cls");
            a1.report_of_current_year();
            break;
        case 4:
            system("cls");
            a1.profit_loss();
            break;
        case 5:
            system("cls");
            cout << "\n Back To Main Menu ";
            break;
        default:
            system("cls");
            cout << "\n Invalide Choice ";
            break;
        }

    } while (ch != 5);
}

void admin::add_fund()
{
    write_data.open("fund.txt", ios::app);

    if (!write_data)
    {
        cout << "\n File Not Open ";
        return;
    }
    cout << "\n Enter The Sector Of Fund (Ex Loan) : - ";
    cin.ignore();
    cin >> place;
    cout << "\n Enter The Amount Of Fund : - ";
    cin >> money;

    total += money;

    write_data << "Fund Sector         = " << place << endl;
    write_data << "Fund Amount         = " << money << endl;
    write_data << "At Time Total Fund  = " << total << endl;

    write_data.close();
}

void admin::see_total_fund()
{
    read_data.open("fund.txt");
    bool found = false;
    if (!read_data)
    {
        cout << "\n File Not Open";
        return;
    }

    while (getline(read_data, line))
    {

        if (line.find("At Time Total Fund  = ") != string::npos)
        {

            orignal_fund = stoi(line.substr(line.find("=") + 1));

            cout << "\n ==================================================" << endl;
            cout << "\n                  Total Balance Of Bank            " << endl;
            cout << "\n ==================================================" << endl;
            cout << "\n |                                                 |" << endl;
            cout << "\n |         Total Main Balance Of Bank  Fund  =      " << orignal_fund;
            cout << "\n |                                                 |" << endl;
            found = true;
        }
    }
    if (found == false)
    {
        cout << "\n The Total Value Not Found ";
    }
    read_data.close();
}
void admin::report_of_current_year()
{
    read_data.open("fund.txt");
    bool found;
    if (!read_data)
    {
        cout << "\n File Not Open";
        return;
    }
    while (getline(read_data, line))
    {

        if (line.find("At Time Total Fund  = ") != string::npos)
        {

            orignal_fund = stoi(line.substr(line.find("=") + 1));
        }
    }

    cout << "\n";
    cout << "====================================================\n";
    cout << "                   BANK OF XYZ\n";
    cout << "           FINANCIAL REPORT OF CUREENT YEAR\n";
    cout << "====================================================\n";
    cout << "\n              BANK SUMMARY\n";
    cout << "----------------------------------------------------\n";
    cout << "\n Total Customers " << setw(20) << ":" << setw(11) << 13000;
    cout << "\n Total Employees " << setw(20) << ":" << setw(11) << 550;
    cout << "\n Total Deposits  " << setw(20) << ":" << setw(4) << "RS." << setw(3) << 95000000;
    cout << "\n Total Withdeawals  " << setw(17) << ":" << setw(4) << "RS." << setw(3) << 40000000;
    cout << "\n Total Loans " << setw(24) << ":" << setw(4) << "RS." << setw(3) << 13500000;
    cout << "\n Total Interest Earned " << setw(14) << ":" << setw(4) << "RS." << setw(3) << 3700000;
    cout << "\n ";
    cout << "\n ";
    cout << "\n====================================================\n";
    cout << "\n                TOTAL  FUND IN BANK DETAIlS        \n";
    cout << "\n====================================================\n";
    cout << "\n|" << setw(50) << "|";
    cout << "\n|  Total Fund Today" << setw(20) << ": " << orignal_fund << setw(11);
    cout << "\n|" << setw(50) << "|";
    cout << "\n ";
    cout << "\n====================================================";
    cout << "\n ";
    cout << "\n----------------------------------------------------";
    cout << "\n                PROFIT SUMMARY                 ";
    cout << "\n----------------------------------------------------";
    cout << "\n Total Income  " << setw(22) << ":" << setw(4) << "RS." << setw(3) << 7000000;
    cout << "\n Total Expenses  " << setw(20) << ":" << setw(4) << "RS." << setw(3) << 2000000;
    cout << "\n Net Profit   " << setw(23) << ":" << setw(4) << "RS." << setw(3) << 5000000;
    cout << "\n----------------------------------------------------";
    read_data.close();
}

void admin::profit_loss()
{
    int income = 7000000;
    int expenses = 2000000;
    int profit_loss;

    profit_loss = income - expenses;

    cout << "\n--------- PROFIT & LOSS ---------\n";

    cout << "\n Total Income   : Rs. " << income;
    cout << "\n Total Expenses : Rs. " << expenses;

    if (profit_loss > 0)
    {
        cout << "\n Total Profit   : Rs. " << profit_loss;
    }
    else if (profit_loss < 0)
    {
        cout << "\n Total Loss     : Rs. " << profit_loss;
    }
    else
    {
        cout << "\n No Profit No Loss";
    }

    read_data.open("fund.txt");
    bool found;
    if (!read_data)
    {
        cout << "\n File Not Open";
        return;
    }
    while (getline(read_data, line))
    {

        if (line.find("At Time Total Fund  = ") != string::npos)
        {

            orignal_fund = stoi(line.substr(line.find("=") + 1));
        }
    }
    read_data.open("fund.txt");

    if (!read_data)
    {
        cout << "\n File Not Open";
        return;
    }
    while (getline(read_data, line))
    {

        if (line.find("At Time Total Fund  = ") != string::npos)
        {

            orignal_fund = stoi(line.substr(line.find("=") + 1));
        }
    }
    cout << "\n Original Fund  : Rs. " << orignal_fund;
    read_data.close();
    cout << "\n---------------------------------\n";
}

//  EMPLOYEE PART
void emp_menu()
{

    cout << "\n = = = = EMPLOOYE MENU = = = = ";
    cout << "\n         1. Add New Account ";
    cout << "\n         2. Display All Acount ";
    cout << "\n         3. Search Account ";
    cout << "\n         4. Update Account ";
    cout << "\n         5. Delete Account ";
    cout << "\n         6. Logout ";
}

// BAKI CHE AHITHI BATHA FUNCTION NE EMP_SWITCH PART MA MUKVANA

void emp_switch_part()
{
    do
    {

        emp_menu();
        cout << "\n Enter Your Choice ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            system("cls");
            e1.add_customer_details();
            break;
        case 2:
            system("cls");
            show_all_customer_data();
            break;
        case 3:
            system("cls");
            e1.search_customer_account();
            break;
        case 4:
            system("cls");
            update_customer_data();
            break;
        case 5:
            system("cls");
            e1.delete_customer();
            break;
        case 6:
            system("cls");
            cout << "\n Back To The Main Menu " << endl;
            break;
        default:
            system("cls");
            cout << "\n Invalide Choice ";
            break;
        }
    } while (ch != 6);
}

void emp::search_customer_account()
{
    e1.emp_checking();
    string name, mobile_line, c_amount, pin;
    long long int ac, an;
    // int am;
    // float am;
    read_data.open("customer.txt", ios::in);

    if (!read_data)
    {
        cout << "\n File Not Open";
        return;
    }

    cout << "\n Enter Your Account Number ";
    cin >> an;

    while (getline(read_data, line))
    {
        if (line.find("Account Number = ") != string::npos)
        {
            ac = stoll(line.substr(line.find("=") + 1));
            if (ac == an)
            {
                getline(read_data, name);
                getline(read_data, mobile_line);
                getline(read_data, c_amount);
                getline(read_data, status);
                getline(read_data, pin);

                cout << "\n DISPLAY THE CUSTOMER DATA  " << endl;
                cout << "\n Customer Account Number = " << ac << endl;
                cout << name << endl;
                cout << mobile_line << endl;
                cout << c_amount << endl;
                cout << status << endl;
                cout << pin << endl;
            }
        }
    }

    read_data.close();
}

void emp::delete_customer()
{
    e1.emp_checking();
    long long int acc, accn;
    string mobile_line, c_amount, pin;
    bool found = false;
    read_data.open("customer.txt", ios::in);
    write_data.open("customer_updated.txt", ios::app);
    if (!read_data || !write_data)
    {
        cout << "\n File Not Open";
        return;
    }

    cout << "\n Enter Customer Account Number ";
    cin >> acc;
    while (getline(read_data, line))
    {

        if (line.find("Customer Amount = ") != string::npos)
        {
            accn = stoll(line.substr(line.find("=") + 1));
            getline(read_data, full_name);
            getline(read_data, mobile_line);
            getline(read_data, c_amount);
            getline(read_data, status);
            getline(read_data, pin);
            if (acc != accn)
            {
                write_data << line;
                write_data << full_name;
                write_data << c_amount;
                write_data << status;
                write_data << pin;
            }
            else
            {
                cout << "\n CUSTOMER DATA FOUND ";
                cout << line;
                cout << full_name;
                cout << mobile_line;
                cout << c_amount;
                cout << status;
                cout << pin;
                found = true;
            }
        }
    }
    if (found == false)
    {
        cout << "\n Data Not Found In Data Base";
    }
    write_data.close();
    read_data.close();
    remove("customer.txt");
    rename("customer_updated.txt", "customer.txt");
}

// customer part here to start
void switch_part_of_customer()
{
    customer c1;
    do
    {
        c1.customer_field_menu();
        cout << "\n Enter Your Choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            system("cls");
            c1.show_my_details();
            break;
        case 2:
            system("cls");
            c1.credit_amount();
            break;
        case 3:
            system("cls");
            c1.withrawal_amount();
            break;
        case 4:
            system("cls");
            cout << "\n Back To The Main Menu ";
            break;
        default:
            system("cls");
            cout << "\n Inavalide Choice ";
            break;
        }

    } while (ch != 5);
}
void customer :: show_my_details()
{
    string name, mobile_line, c_amount, pin;
    long long int ac, an;

    read_data.open("customer.txt", ios::in);

    if (!read_data)
    {
        cout << "\n File Not Open";
        return;
    }

    cout << "\n Enter Your Account Number ";
    cin >> an;

    while (getline(read_data, line))
    {
        if (line.find("Account Number = ") != string::npos)
        {
            ac = stoll(line.substr(line.find("=") + 1));
            if (ac == an)
            {
                getline(read_data, name);
                getline(read_data, mobile_line);
                getline(read_data, c_amount);
                getline(read_data, status);
                getline(read_data, pin);
                cout << "\n DISPLAY THE CUSTOMER DATA  " << endl;
                cout << "\n Customer Account Number = " << ac << endl;
                cout << name << endl;
                cout << mobile_line << endl;
                cout << c_amount << endl;
                cout << status << endl;
                cout << pin << endl;
            }
        }
    }

    read_data.close();
}

void customer :: credit_amount()
{
    string name, mobile_line, amount_line, status_line, pin_line;
    long long int acn, ac;
    int old_amount, credit, user_pin, old_pin;
    bool found = false;

    cout << "\n Enter Your Account Number: ";
    cin >> acn;

    read_data.open("customer.txt", ios::in);
    write_data.open("temp.txt", ios::out);

    if (!read_data || !write_data)
    {
        cout << "\n File Not Open!";

        if (read_data.is_open())
            read_data.close();

        if (write_data.is_open())
            write_data.close();

        return;
    }

    while (getline(read_data, line))
    {
        if (line.find("Account Number = ") != string::npos)
        {
            ac = stoll(line.substr(line.find("=") + 1));

            getline(read_data, name);
            getline(read_data, amount_line);
            getline(read_data, mobile_line);
            getline(read_data, status_line);
            getline(read_data, pin_line);
            if (ac == acn)
            {
                found = true;

                cout << "\n Customer Details";
                cout << "\n Account Number = " << ac;
                cout << "\n " << name;
                cout << "\n " << amount_line;
                cout << "\n " << mobile_line;
                cout << "\n " << status_line;
                cout << "\n " << pin_line;
                old_amount = stof(amount_line.substr(amount_line.find("=") + 1));
                old_pin = stoi(pin_line.substr(pin_line.find("=") + 1));
                cout << "\n Enter Your Transaction PIN";
                cin >> user_pin;
                if (pin == user_pin)
                {
                    cout << "\n Enter Your Amount You Want To Credit: ";
                    cin >> credit;

                    old_amount = old_amount + credit;

                    amount_line = "Customer Amount = " + to_string(old_amount);

                    cout << "\n Amount Credited Successfully!";
                    cout << "\n Updated Balance = " << old_amount;
                }
            }

            write_data << "Account Number = " << ac << endl;
            write_data << name << endl;
            write_data << amount_line << endl;
            write_data << mobile_line << endl;
            write_data << status_line << endl;
        }
    }

    read_data.close();
    write_data.close();

    if (found == true)
    {
        remove("customer.txt");
        rename("temp.txt", "customer.txt");

        cout << "\n Customer Data Saved Successfully!";
    }
    else
    {
        remove("temp.txt");
        cout << "\n Account Number Not Found!";
    }
}

void customer :: withrawal_amount()
{
    string name, mobile_line, amount_line, status_line, pin_line;
    long long int acn, ac;
    int old_amount, debit, user_pin, old_pin;
    bool found = false;

    cout << "\n Enter Your Account Number: ";
    cin >> acn;

    read_data.open("customer.txt", ios::in);
    write_data.open("temp.txt", ios::out);

    if (!read_data || !write_data)
    {
        cout << "\n File Not Open!";

        if (read_data.is_open())
            read_data.close();

        if (write_data.is_open())
            write_data.close();

        return;
    }

    while (getline(read_data, line))
    {
        if (line.find("Account Number = ") != string::npos)
        {
            ac = stoll(line.substr(line.find("=") + 1));

            getline(read_data, name);
            getline(read_data, amount_line);
            getline(read_data, mobile_line);
            getline(read_data, status_line);
            getline(read_data, pin_line);

            if (ac == acn)
            {
                found = true;

                cout << "\n Customer Details";
                cout << "\n Account Number = " << ac;
                cout << "\n " << name;
                cout << "\n " << amount_line;
                cout << "\n " << mobile_line;
                cout << "\n " << status_line;
                cout << "\n " << pin_line;
                old_amount = stof(amount_line.substr(amount_line.find("=") + 1));
                old_pin = stoi(pin_line.substr(pin_line.find("=") + 1));

                cout << "\n Enter Your Transaction PIN";
                cin >> user_pin;
                if (pin == user_pin)
                {
                    cout << "\n Enter Your Amount You Want To Debit : ";
                    cin >> debit;

                    old_amount = old_amount - debit;

                    amount_line = "Customer Amount = " + to_string(old_amount);

                    cout << "\n Amount Debited Successfully!";
                    cout << "\n Updated Balance = " << old_amount;
                }
            }

            write_data << "Account Number = " << ac << endl;
            write_data << name << endl;
            write_data << amount_line << endl;
            write_data << mobile_line << endl;
            write_data << status_line << endl;
        }
    }

    read_data.close();
    write_data.close();

    if (found == true)
    {
        remove("customer.txt");
        rename("temp.txt", "customer.txt");

        cout << "\n Customer Data Saved Successfully!";
    }
    else
    {
        remove("temp.txt");
        cout << "\n Account Number Not Found!";
    }
}
