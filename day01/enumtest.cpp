#include <iostream>

enum spectrum
{
    red,
    orange,
    yellow,
    green,
    blue,
    violet,
    indigo,
    ultraviolet
};

int main()
{
    using namespace std;

    spectrum spec;

    cout << spec << endl;
    return 0;
}