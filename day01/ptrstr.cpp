#include <cstring>
#include <iostream>

int main()
{
    using namespace std;
    char flower[10] = "rose";
    cout << flower << "s are red\n";

    char animal[20] = "bear";
    const char *bird = "wren"; // bird holds address of string
    char *ps;

    cout << animal << " and ";
    cout << bird << "\n";
    cout << (int *)ps << endl;
    // bird = ps;
    cout << &bird << endl;
    cout << (int *)bird << endl;
    // cout << ps << "\n"; // may display garbage, may cause a crash

    cout << "Enter a kind of animal: ";
    cin >> animal;

    ps = animal;
    cout << ps << "!\n";
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;

    ps = new char[strlen(animal) + 1];
    strcpy(ps, animal);
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;
    delete[] ps;

    return 0;
}