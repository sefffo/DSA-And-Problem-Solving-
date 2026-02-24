#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
    }

    ~LinkedList()
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
            cout << "empty";
        }
        else
        {
            while (temp != nullptr)
            {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr)
                {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }

    Node *getHead()
    {
        return head;
    }

    void makeEmpty()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *currentNode = head;
            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - Convert binary number in list to decimal           |
    //   | - Return type: int                                   |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Use a single pointer: 'current'                    |
    //   | - Initialize an integer 'num' to 0                   |
    //   | - Loop through the list                              |
    //   | - Use the formula: num = num * 2 + current->value    |
    //   | - Return 'num' as the decimal value                  |
    //   +======================================================+

    int binaryToDecimal()
    {
        // Initialize result to 0
        int num = 0;

        // Start from the head of the list
        Node *current = head;

        // Traverse through the entire list
        while (current != nullptr)
        {
            // Apply the formula: shift left (multiply by 2) and add current digit
            num = num * 2 + current->value;

            // Move to the next node
            current = current->next;
        }

        // Return the decimal result
        return num;
    }
};
