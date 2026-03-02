#include <iostream>

#include <stack>

using namespace std;

string reverseString(const string &str)
{

    stack<char> s;

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function reverses the input string 'str'.    |
    //   | - Uses a stack to hold the characters.              |
    //   | - Pops from stack and appends to 'reversedString'.  |
    //   | - Return type: string                               |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use a stack to hold each character of the string. |
    //   | - Push each character of 'str' onto the stack.      |
    //   | - Pop from the stack and append to 'reversedString' |
    //   |   until the stack is empty.                         |
    //   | - Return the reversed string.                       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    for (size_t i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string revWord;
    for (size_t i = 0; i < str.length(); i++)
    {

        revWord += s.top();
        s.pop();
    }
    return revWord;
}

int main()
{

    cout << reverseString("masr om el donia w htb'a ad el donia");
}