#include <iostream>
#include <vector>

class MyStack
{
private:
    std::vector<int> m_index;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        index.emplace_back(x);
    }

    int pop()
    {
        int _x = index.back();
        index.erase(index.end() - 1);
        return _x;
    }

    int top()
    {
        return index.back();
    }

    bool empty()
    {
        if (index.size() == 0) return true;
        return false;
    }
};

int main()
{
    using namespace std;
    MyStack m1;
    m1.push(1);
    m1.push(2);
    cout << m1.top() << endl;
    cout << m1.empty() << endl;

    return 0;
}