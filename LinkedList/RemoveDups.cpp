#include <iostream>
#include <unordered_set>

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
    //   | - Remove duplicate nodes from the list               |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Use two pointers: 'current' and 'runner'           |
    //   | - 'current' scans each node                          |
    //   | - 'runner' checks for duplicates ahead               |
    //   | - If duplicate found, delete it                      |
    //   | - Update 'next' pointers and reduce length           |
    //   | - No return value, list updated in-place             |
    //   +======================================================+



    //when i study the sets ill solve using it 
    void removeDuplicates()
    {
        unordered_set<int> values;
        Node *previous = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            if (values.find(current->value) != values.end())
            {
                previous->next = current->next;
                delete current;
                current = previous->next;
                length -= 1;
            }
            else
            {
                values.insert(current->value);
                previous = current;
                current = current->next;
            }
        }
    }
    void removeDuplicates()
    {
        Node *current = head;

        while (current != nullptr)
        {
            Node *runner = current; //,ohem an a5od bali hena

            while (runner != nullptr)
            {

                if (runner->next == nullptr)
                {
                    break; // to ski the loop
                }

                if (runner->next->value == current->value)
                {
                    runner->next = runner->next->next;
                    length--;
                }
                else
                {
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }
};

int main()
{

    LinkedList *list = new LinkedList(1);
    list->append(2);
    list->append(1);
    list->append(4);
    list->append(5);
    list->append(5);

    list->removeDuplicates();
    list->printList();

    cout << list->getLength();

    return 0;
}
