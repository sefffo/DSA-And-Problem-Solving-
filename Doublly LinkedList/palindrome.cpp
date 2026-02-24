#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "empty" << endl;
            return;
        }
        while (temp->next != nullptr)
        {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << temp->value << endl;
    }

    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    int getLength()
    {
        return length;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This is the isPalindrome method.                  |
    //   | - It checks if the list is a palindrome or not.     |
    //   | - Return type: bool                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - A list with 0 or 1 node is a palindrome.          |
    //   | - Create two pointers: forwardNode and backwardNode.|
    //   | - Loop from the start to the middle of the list.    |
    //   | - Compare forwardNode and backwardNode values.      |
    //   | - If any pair is not equal, return false.           |
    //   | - Otherwise, return true.                           |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    bool isPalindrome()
    {
        Node *forward = head;
        Node *Backward = tail;

        if (length < 1)
            return true;
        for (int i = 0; i < length / 2; i++)
        {
            if (forward->value != Backward->value)
                return false;
            forward = forward->next;
            Backward = Backward->prev;
        }
        return true;
    }

    //1<->2<->4<->2<->1


};

int main()
{
    DoublyLinkedList *list = new DoublyLinkedList(1);

    list->append(2);

    cout << list->isPalindrome();
}
