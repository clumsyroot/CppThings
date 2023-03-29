#include <iostream>
#include <string>

#define MAX 1000

using namespace std;

struct Person
{
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct Addressbooks
{
    struct Person personArray[MAX];
    int count;
};

void emptyAddressBooks(Addressbooks *abs)
{
    abs->count = 0;
    system("clear");
    cout << "Done!" << endl;
}

void showMenu()
{
    cout << "1.Add a contact" << endl;
    cout << "2.Show all contact" << endl;
    cout << "3.Delete contact" << endl;
    cout << "4.Search contact" << endl;
    cout << "5.Modify contact" << endl;
    cout << "6.Empty contact" << endl;
    cout << "0.Quit" << endl;
}

int searchPerson(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->count; i++)
    {
        if (abs->personArray[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

void modifyPerson(Addressbooks *abs)
{
    cout << "input a name...\t";
    string name;
    cin >> name;
    int idx = searchPerson(abs, name);
    if (idx == -1)
    {
        cout << "no contact named " << name;
        cout << ", check it out!" << endl;
    }
    else
    {
        int sex;
        int age;
        string phone;
        string address;
        cout << "input contact name...";
        cin >> name;
        cout << "input contact sex...";
        cin >> sex;
        cout << "input contact age...";
        cin >> age;
        cout << "input contact phone...";
        cin >> phone;
        cout << "input contact address...";
        cin >> address;

        abs->personArray[idx].name = name;
        abs->personArray[idx].age = age;
        abs->personArray[idx].sex = sex;
        abs->personArray[idx].phone = phone;
        abs->personArray[idx].address = address;
    }
}

void searchPersonAndShow(Addressbooks *abs)
{
    cout << "input a name...\t";
    string name;
    cin >> name;
    int idx = searchPerson(abs, name);
    if (idx == -1)
    {
        cout << "no contact named " << name;
        cout << ", check it out!" << endl;
    }
    else
    {
        cout << "name: " << abs->personArray[idx].name;
        cout << " sex: " << abs->personArray[idx].sex;
        cout << " age: " << abs->personArray[idx].age;
        cout << " address: " << abs->personArray[idx].address;
        cout << " phone: " << abs->personArray[idx].phone << endl;
    }
}

void deletePerson(Addressbooks *abs)
{
    cout << "input a name...\t";
    string name;
    cin >> name;
    int index = searchPerson(abs, name);
    if (index == -1)
    {
        cout << "no contact named " << name;
        cout << ", check it out!" << endl;
    }
    else
    {
        for (int i = index; i < abs->count; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->count--;
        system("clear");
        cout << "Done!" << endl;
    }
}

void showPerson(Addressbooks *abs)
{
    if (abs->count == 0)
    {
        system("clear");
        cout << "Empty! Please add a contact first!" << endl;
        return;
    }
    else
    {
        system("clear");
        for (int i = 0; i < abs->count; i++)
        {

            cout << "name: " << abs->personArray[i].name;
            cout << " sex: " << abs->personArray[i].sex;
            cout << " age: " << abs->personArray[i].age;
            cout << " address: " << abs->personArray[i].address;
            cout << " phone: " << abs->personArray[i].phone << endl;
        }
    }
    return;
}

void addPerson(Addressbooks *abs)
{
    if (abs->count == MAX)
    {
        cout << "FULL!";
        return;
    }
    else
    {
        string name;
        int sex;
        int age;
        string phone;
        string address;

        cout << "input contact name...";
        cin >> name;
        cout << "input contact sex...";
        cin >> sex;
        cout << "input contact age...";
        cin >> age;
        cout << "input contact phone...";
        cin >> phone;
        cout << "input contact address...";
        cin >> address;

        abs->personArray[abs->count].name = name;
        abs->personArray[abs->count].age = age;
        abs->personArray[abs->count].sex = sex;
        abs->personArray[abs->count].phone = phone;
        abs->personArray[abs->count].address = address;

        abs->count++;
        system("clear");
        cout << "Done" << endl;
        return;
    }
}

int main()
{
    Addressbooks address_books;
    address_books.count = 0;
    int select = 0;

    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 0:
            return 0;
        case 1:
            addPerson(&address_books);
            break;
        case 2:
            showPerson(&address_books);
            break;
        case 3:
            deletePerson(&address_books);
            break;
        case 4:
            searchPersonAndShow(&address_books);
            break;
        case 5:
            modifyPerson(&address_books);
            break;
        case 6:
            emptyAddressBooks(&address_books);
            break;
        }
    }
    return 0;
}