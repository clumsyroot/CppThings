#include <stack>

class CQueue
{
    std::stack<int> in_stk, out_stk;

public:
    CQueue()
    {
    }

    void in2out()
    {
        int cur;
        while (!in_stk.empty())
        {
            cur = in_stk.top();
            in_stk.pop();
            out_stk.push(cur);
        }
    }

    void appendTail(int value)
    {
        in_stk.push(value);
    }

    int deleteHead()
    {
        // if (!in_stk.empty()) in2out();
        // if (out_stk.empty()) return -1;
        if (out_stk.empty())
        {
            if (in_stk.empty())
            {
                return -1;
            }
            in2out();
        }
        int cur = out_stk.top();
        out_stk.pop();
        return cur;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */