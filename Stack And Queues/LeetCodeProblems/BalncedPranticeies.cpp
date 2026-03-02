#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool isBalancedParentheses(const string &parentheses)
{

    stack<char> s;
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function checks if the input string          |
    //   |   'parentheses' has balanced parentheses.           |
    //   | - Uses a stack to hold the open parentheses.        |
    //   | - Return type: bool                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use a stack to hold open parentheses.             |
    //   | - Push '(' onto the stack.                          |
    //   | - When encountering ')', check if stack is empty    |
    //   |   or top of stack is not '('. If so, return false.  |
    //   | - Otherwise, pop from the stack.                    |
    //   | - At the end, if stack is empty, return true.       |
    //   | - Otherwise, return false.                          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    if (parentheses.empty())
    {
        return true;
    }

    for (size_t i = 0; i < parentheses.length(); i++)
    {
        if (parentheses[i] == '(')
        {
            s.push(parentheses[i]);
        }

        if (parentheses[i]==')')
        {
            if(s.empty())
            {
                return false;
            }
            s.pop();
        }
    }

    if (s.empty())
    {
        return true;
    }

    return false;
}

int main()
{
    cout << isBalancedParentheses("(()))");
}
