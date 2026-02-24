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
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        length = 1;
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

    int getLength()
    {
        return length;
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
        length = 0;
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
        length++;
    }

    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - Partition list around value x                      |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Create two dummy nodes for two new lists           |
    //   | - One list for nodes less than x                     |
    //   | - Another list for nodes greater or equal to x       |
    //   | - Loop through original list                         |
    //   | - Assign nodes to new lists based on value           |
    //   | - Merge the two new lists                            |
    //   | - Update the original list's head                    |
    //   +======================================================+

    void PartitionList(int x)
    {

        Node *D1 = new Node(0);
        Node *D2 = new Node(0);

        Node *prev1 = D1;
        Node *prev2 = D2;

        Node *current = head;

        while (current)
        {

            if (current->value < x)
            {
                prev1->next = current;
                prev1 = current;
            }
            else if (current->value >= x)
            {
                prev2->next = current;
                prev2 = current;
            }
            current = current->next;
        }

        // elz222
        if(!D2->next)
        {
            prev1->next = nullptr;
        }

        prev1->next = D2->next; // Link end of first partition to start of second
        prev2->next = nullptr;

        head = D1->next;
        delete D1;
        delete D2;
    }
};

int main()
{

    LinkedList *list = new LinkedList(1);
    list->append(4);
    list->append(3);
    list->append(2);
    list->append(5);
    list->append(2);

    cout << "Original List: ";
    list->printList();

    int x = 3;
    list->PartitionList(x);

    cout << "Partitioned List around " << x << ": ";
    list->printList();
}
