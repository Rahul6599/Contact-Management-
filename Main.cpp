#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

string fname, lname, phone_num;

bool check_digit(string x)
{
    bool check = true;

    for (int i = 0; i < x.length(); i++)
    {
        if (!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            return false;
        }
    }
    return true;
}

void Add_Contact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");

    cout << "\n\tEnter First Name:: ";
    cin >> fname;
    cout << "\n\tEnter Last Name:: ";
    cin >> lname;
    cout << "\n\tEnter 10 Digit Phone-Number:: ";
    cin >> phone_num;

    if (phone_num.length() == 10)
    {
        if (check_digit(phone_num))
        {
            if (phone.is_open())
            {
                phone << fname<<" "<<lname<<" "<<phone_num<<" "<<"\n";
                cout << "\n\tContact Saved Successfully";
            }
            else
            {
                cout << "\n\tError in Opening File";
            }
        }
        else
        {
            cout << "\n\tPhone Number must contain Number Only";
        }
    }
    else
    {
        cout << "\n\tPhone Number must contain 10 Digits";
    }

    phone.close();
}

void Search_Contact()
{
    bool found = false;

    ifstream myfile("number.txt");

    string keyword;
    cout << "\n\tEnter Name for Search:: ";
    cin >> keyword;

    while (myfile >> fname >> lname >> phone_num)
    {
        if (keyword == fname || keyword == lname)
        {
            system("cls");
            cout << "\n\t\tContact Details....";
            cout << "\n\tFirst Name:: " << fname;
            cout << "\n\tLast Name:: " << lname;
            cout << "\n\tPhone Number:: " << phone_num;
            found = true;
            break;
        }
    }

    if (found==false)
        cout << "\n\tNo Such Contact Found!";
}

void Help()
{
    system("cls");
    cout << "\n\n\t\tSORRY FOR INCONVIENCE,HOW CAN I HELP YOU !";
}

void Self_Exit()
{
    system("cls");
    cout << "\n\n\tTHANKYOU FOR USING !";
    exit(1);
}

int main()
{
    int choice;

    system("cls");
    system("color 0C");

    cout << "\n\n\n\t\t Contact Management....";

    cout << "\n\n\n\t1.Add Contact"
         << "\n\t"
         << "2.Search Contact\n\t"
         << "3.Help\n\t"
         << "4.Exit\n\t";

    cin >> choice;

    switch (choice)
    {
    case 1:
        Add_Contact();
        break;
    case 2:
        Search_Contact();
        break;
    case 3:
        Help();
        break;
    case 4:
        Self_Exit();
        break;
    default:
        cout << "\n\n\tINVALID INPUT";
        cout << "\n\tPress Any Key to Continue";
        getch();
        main();
    }

    return 0;
}