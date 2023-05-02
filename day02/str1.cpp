#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string one("Lottery Winner!");
    cout << "one -- " << one << endl;
    string two(20, '$');
    cout << "two -- " << two << endl;
    string three(one);
    one += " Oops";
    cout << "one -- " << one << endl;
    two = "Sorry! That was ";
    three[0] = 'P';
    string four;
    four = two + three;
    cout << "four -- " << four << endl;
    char alls[] = "All's well that ends well";
    string five(alls, 20);
    cout << "five -- " << five << endl;
    string six(alls + 6, alls + 10);
    cout << "six -- " << six << endl;
    string seven(&five[6], &five[10]);
    cout << "seven -- " << seven << ", ";
    string eight(four, 7, 16);
    cout << "eight -- " << eight << " in motion!" << endl;

    return 0;
}