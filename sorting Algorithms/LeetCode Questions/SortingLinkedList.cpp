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
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
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
            tail = newNode;
        }
        length++;
    }

    void deleteFirst()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }

    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method sorts the linked list using the       |
    //   |   Bubble Sort algorithm.                            |
    //   | - Starts at the head node and iteratively swaps     |
    //   |   adjacent nodes if they are in the wrong order.    |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses two nested while loops for iteration.        |
    //   | - Utilizes a 'sortedUntil' node to optimize.        |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    void BubbleSort()
    {
        if (length == 0 || length == 1)
        {
            return;
        }

        Node *current = nullptr;
        Node *sortedUntil = nullptr;

        while (sortedUntil != head)
        {
            current = head;
            while (current->next != sortedUntil)
            {
                if (current->next->value < current->value)
                {
                    int temp = current->value;
                    current->value = current->next->value;
                    current->next->value = temp;
                }
                current = current->next;
            }
            sortedUntil = current;
        }
    }
    // the way i thout about
    void bubbleSort()
    {
        if (length == 0 || length == 1)
        {
            return;
        }

        Node *current = nullptr;
        bool swapped = false;

        while (true)
        {
            swapped = false;
            current = head;
            while (current->next)
            {
                if (current->next->value < current->value)
                {
                    int temp = current->value;
                    current->value = current->next->value;
                    current->next->value = temp;
                    swapped = true;
                }
                current = current->next;
            }
            if (swapped == false)
                break;
        }
    }

    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method sorts the linked list using the       |
    //   |   Selection Sort algorithm.                         |
    //   | - Iterates through the list to find the smallest    |
    //   |   node and swaps it with the current node.          |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses nested while loops for traversal.            |
    //   | - Swaps values, not nodes, for simplicity.          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    void selectionSort()
    {
        Node *MinVal = nullptr;
        Node *current = head;

        if (length == 0 || length == 1)
        {
            return;
        }

        while (current->next)
        {
            MinVal = current;
            Node *runner = current->next;
            while (runner != nullptr)
            {
                if (MinVal->value > runner->value)
                {
                    MinVal = runner;
                }
                runner = runner->next;
            }

            int temp = current->value;
            current->value = MinVal->value;
            MinVal->value = temp;

            current = current->next;
        }
    }

    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method sorts the linked list using           |
    //   |   the Insertion Sort algorithm.                     |
    //   | - Divides the list into sorted and unsorted parts.  |
    //   | - Iterates through unsorted part and inserts each   |
    //   |   node into the sorted part at the right position.  |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses two sub-lists to divide original list.       |
    //   | - Uses while loops for list traversal.              |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    void insertionSort()
    {
        if (length == 0 || length == 1)
        {
            return;
        }

        Node *sorted = nullptr;
        Node *current = head;


        while (current != nullptr)
        {
            Node *next = current->next;

            if (sorted == nullptr || sorted->value >= current->value)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Node *temp = sorted;
                while (temp->next != nullptr && temp->next->value < current->value)
                {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;

    }
};
int main()
{
    LinkedList *list = new LinkedList(3);

    list->append(1);

    list->append(2);

    list->printList();

    // list->bubbleSort();
    list->selectionSort();

    list->printList();
}