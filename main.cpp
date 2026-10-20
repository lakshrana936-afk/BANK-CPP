#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int flag = 0, ch; // checking admin details
float salary, pf;
long long int mobile_number;
string line, line1;

// FILE MAGMENT SYSTEM

ofstream write_data;
ifstream read_data;

// CUSTOMER PART VARIABLES

int pin, cus_id;
float amount;
string full_name, status;
long long int account_number;
// Financial Part Variables

float money, total = 0, orignal_fund;
string place;

// Admin In Emp show Details And Add Function
void show_emp_details();
void add_emp_details();
void search_emp();
void delete_emp_details();
// Admin In Customer Details And other Function

void show_all_customer_data();
void update_customer_data();

// Admin In Financial Report Part

void last_year_report();
void financial_part();
void add_fund();
void see_total_fund();
void report_of_current_year();
void profit_loss();
// Admin Main Function Part
void admin_check_details();
void show_admin_details_menu();

// EMPLOOYE PART

void emp_menu();

// CUSTOMER PART

void emp_switch_part();
void add_customer_details();
void search_customer_account();
void delete_customer();
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
};
class customer
{
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
    emp e1;
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
        flag = 2;
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
                delete_emp_details();

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
                last_year_report();
                break;
            case 8:
                system("cls");
                financial_part();
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
    }

    if (flag == 2)
    {
        cout << "\n Get lost........";
    }

    write_data.close();
}

void search_emp()
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
void delete_emp_details()
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

    admin_check_details();

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
    admin_check_details();

    read_data.open("customer.txt", ios::in);
    write_data.open("customer_update.txt", ios::app);

    int customer_id, cus_id, choice;
    string line, name, mobile_line, updatede_status;
    bool found = false;

    if (!read_data || !write_data)
    {
        cout << "\n File Not Found!";
        return;
    }

    if (flag == 1)
    {
        cout << "\n Enter Customer Searching ID: ";
        cin >> customer_id;

        while (getline(read_data, line))
        {
            if (line.find("Customer ID = ") != string::npos)
            {
                cus_id = stoi(line.substr(line.find("=") + 1));

                getline(read_data, name);
                getline(read_data, mobile_line);

                if (cus_id == customer_id)
                {
                    found = true;

                    cout << "\n Customer Found!";
                    cout << "\n " << line;
                    cout << "\n " << name;
                    cout << "\n " << mobile_line;

                    cout << "\n 1. Update Customer Name";
                    cout << "\n 2. Update Customer Mobile Number";
                    cout << "\n 3. Update Customer Account Status";
                    cout << "\n Enter Your Choice: ";
                    cin >> choice;

                    if (choice == 1)
                    {
                        cout << "\n Enter New Customer ID: ";
                        cin >> cus_id;

                        line = "Customer ID = " + to_string(cus_id);
                    }
                    else if (choice == 2)
                    {
                        cout << "\n Enter New Customer Name: ";
                        cin.ignore();
                        getline(cin, name);

                        name = "Customer Name = " + name;
                    }
                    else if (choice == 3)
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

                    else if (choice == 4)
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

                write_data << line << endl;
                write_data << name << endl;
                write_data << mobile_line << endl;
                write_data << updatede_status << endl;
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

void add_customer_details()
{
    admin_check_details();

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

        write_data.close();
    }

    if (flag == 2)
    {
        cout << "\n Get Lost ....";
    }
}

void last_year_report()
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

void financial_part()
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
            add_fund();
            break;
        case 2:
            system("cls");
            see_total_fund();
            break;
        case 3:
            system("cls");
            report_of_current_year();
            break;
        case 4:
            system("cls");
            profit_loss();
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

void add_fund()
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

void see_total_fund()
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
void report_of_current_year()
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

void profit_loss()
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
            add_customer_details();
            break;
        case 2:
            system("cls");
            show_all_customer_data();
            break;
        case 3:
            system("cls");
            search_customer_account();
            break;
        case 4:
            system("cls");
            update_customer_data();
            break;
        case 5:
            system("cls");
            delete_customer();
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

void search_customer_account()
{
    string name, mobile_line, c_amount;
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

                cout << "\n DISPLAY THE CUSTOMER DATA  " << endl;
                cout << "\n Customer Account Number = " << ac << endl;
                cout << name << endl;
                cout << mobile_line << endl;
                cout << c_amount << endl;
                cout << status << endl;
            }
        }
    }

    read_data.close();
}

void delete_customer()
{
    long long int acc, accn;
    string mobile_line, c_amount;
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
            if (acc != accn)
            {
                write_data << line;
                write_data << full_name;
                write_data << c_amount;
                write_data << status;
            }
            else
            {
                cout << "\n CUSTOMER DATA FOUND ";
                cout << line;
                cout << full_name;
                cout << mobile_line;
                cout << c_amount;
                cout << status;
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