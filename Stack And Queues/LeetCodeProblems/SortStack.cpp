#include <stack>
#include <iostream>
using namespace std;

void sortStack(stack<int> &inputStack)
{

    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - This function sorts the input stack 'inputStack'.  |
    //   | - Uses an additional stack for sorting.              |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Create an additional stack.                        |
    //   | - Pop elements from 'inputStack' and push them       |
    //   |   into 'additionalStack' in sorted order.            |
    //   | - Use a temporary variable to hold the top element   |
    //   |   of 'inputStack'.                                   |
    //   | - Move elements back to 'additionalStack' if needed. |
    //   | - Finally, move all elements back to 'inputStack'.   |
    //   | - Check output from Test.cpp in "User logs".         |
    //   +======================================================+

    stack<int> additionalStack;
    int temp;

    while (!inputStack.empty())
    {
        temp = inputStack.top();
        inputStack.pop();

        while (!additionalStack.empty() && additionalStack.top() > temp)
        {
            inputStack.push(additionalStack.top());

            additionalStack.pop();
        }

        additionalStack.push(temp);
    }
    //3shan adif el anaser el mtrtba tani fe el main stack 
    while (!additionalStack.empty())
    {
        inputStack.push(additionalStack.top());
        additionalStack.pop();//3shan ahrk el el elements mn el additionalStack lel inputStack 3shan a7ot el sorted elements fe el inputStack
    }
}

