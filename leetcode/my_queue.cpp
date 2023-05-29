#include <iostream>
#include <stack>

// 用栈实现队列
class MyQueue
{
    std::stack<int> inStack, outStack;

    void in2out()
    {
        while (!inStack.empty())
        {
            outStack.emplace(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        inStack.emplace(x);
    }

    int pop()
    {
        while (outStack.empty())
        {
            in2out();
        }
        int ans = outStack.top();
        outStack.pop();
        return ans;
    }

    int peek()
    {
        if (outStack.empty())
        {
            in2out();
        }
        return outStack.top();
    }

    bool empty()
    {
        return inStack.empty() && outStack.empty();
    }
};

int main()
{
    using namespace std;
    MyQueue mq;
    mq.push(1);
    mq.push(2);
    mq.push(3);
    mq.peek();

    return 0;
}