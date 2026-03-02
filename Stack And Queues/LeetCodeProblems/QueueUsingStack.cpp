#include <stack>
#include <climits>
#include <iostream>

using namespace std;

class QueueUsingTwoStacks
{
private:
    stack<int> stack1, stack2;

public:
    int front()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty())
        {
            return INT_MIN;
        }

        return stack2.top();
    }

    // int front()
    // {
    //     if (stack1.empty())
    //     {
    //         return INT_MIN;
    //     }
    //     return stack1.top();
    // }

    bool isEmpty()
    {
        return stack1.empty() && stack2.empty();
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This method adds a new value to the end of the    |
    //   |   queue (enqueue) using 'stack1'.                   |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use 'stack1' to enqueue a new value.              |
    //   | - Simply push the new value onto 'stack1'.          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    // void enqueue(int value)
    // {
    //     while (!stack1.empty())
    //     {
    //         stack2.push(stack1.top());
    //         stack1.pop();
    //     }

    //     stack1.push(value);

    //     while (!stack2.empty())
    //     {
    //         stack1.push(stack2.top());
    //         stack2.pop();
    //     }

    // }

    void enqueue(int value)
    {
        stack1.push(value);
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This method removes a value from the front of the |
    //   |   queue (dequeue) using 'stack2'.                   |
    //   | - If 'stack2' is empty, it fills 'stack2' from      |
    //   |   'stack1'.                                         |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - If 'stack2' is empty, pop all elements from       |
    //   |   'stack1' into 'stack2'.                           |
    //   | - Then, pop the top element of 'stack2'.            |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+


    void dequeue()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty())
        {
            cout << "Queue is Empty";
            return;
        }

        stack2.pop();
    }
};
