#include <cstring>
#include <iostream>

char *getname(void);

int main()
{
    using namespace std;
    char *name;
    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete[] name;

    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete[] name;

    return 0;
}

char *getname()
{
    char temp[80];
    std::cout << "Enter last name: ";
    std::cin >> temp;
    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);
    return pn;
}