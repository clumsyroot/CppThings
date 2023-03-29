#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(100);
    cout << "vector size = " << vec.size() << endl;
    cout << "vector capacity = " << vec.capacity() << endl;

    for (int i = 0; i < 5; i++)
    {
        int new_num;
        cout << "please input a number... ";
        cin >> new_num;
        vec.push_back(new_num);
    }
    cout << "vector size = " << vec.size() << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        cout << "value of vec[" << i << "]"
             << " is " << vec[i] << endl;
    }

    // iterator
    auto v = vec.begin();
    cout << "value of vec is: ";
    while (v != vec.end())
    {
        cout << *v << ", ";
        v++;
    }
    cout << endl;

    return 0;
}