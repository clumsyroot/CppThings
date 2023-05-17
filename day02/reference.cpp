#include <iostream>

double refcube(const double &ra)
{
    return ra * ra * ra;
}

int main()
{
    using namespace std;

    double side = 3.0;
    double *pd = &side;
    double &rd = side;
    long edge = 5L;
    double len[4] = {1.0, 2.0, 3.0, 4.0};
    double c1 = refcube(side);
    double c2 = refcube(len[2]);
    double c3 = refcube(rd);
    double c4 = refcube(*pd);
    double c5 = refcube(edge);
    double c6 = refcube(7.0);
    double c7 = refcube(side + 10.0);

    cout << "side is " << side << endl;
    cout << "*pd = &side ";
    cout << "pd is " << pd << " *pd is " << *pd << endl;
    cout << "&rd = side ";
    cout << " rd is " << rd << endl;
    cout << "c1 is " << c1 << endl;
    cout << "c2 is " << c2 << endl;
    cout << "c3 is " << c3 << endl;
    cout << "c4 is " << c4 << endl;
    cout << "c5 is " << c5 << endl;
    cout << "c6 is " << c6 << endl;
    cout << "c7 is " << c7 << endl;

    return 0;
}