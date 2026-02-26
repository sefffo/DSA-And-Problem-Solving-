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
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
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
        if (length == 0)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        length++;
    }

    void reverseBetween(int startIndex, int endIndex)
    {
        //   +===================================================+
        //   |               WRITE YOUR CODE HERE                |
        //   | Description:                                      |
        //   | - Reverses a portion of a doubly linked list      |
        //   |   between startIndex and endIndex (inclusive).    |
        //   | - The rest of the list remains unchanged.         |
        //   |                                                   |
        //   | Behavior:                                         |
        //   | - A dummy node is used to simplify edge cases     |
        //   |   when reversing from the head.                   |
        //   | - `prev` is positioned just before the reversal   |
        //   |   section.                                        |
        //   | - Nodes are extracted one by one and moved to the |
        //   |   front of the sublist, reversing the segment.    |
        //   | - All `.next` and `.prev` pointers are correctly  |
        //   |   updated during each step.                       |
        //   | - Updates the list's head and deletes dummy node. |
        //   +===================================================+

        Node *D = new Node(0);
        if (head != nullptr) head->prev = D;
        D->next = head;

        Node *prev = D;

        for (int i = 0; i < startIndex; i++)
        {
            prev = prev->next;
            if (prev == nullptr)
            {
                head = D->next;
                delete D;
                return; // List too short, exit safely
            }
        }

        Node *current = prev->next;

        if (current == nullptr)
        {
            head = D->next;
            delete D;
            return; // nothing to revesre
        }

        for (int i = 0; i < endIndex - startIndex; i++)
        {
            Node *ToMove = current->next;
            current->next = ToMove->next;
            ToMove->next = prev->next;
            ToMove->prev = prev;
            prev->next = ToMove;
        }
        head = D->next;
        delete D;
    }
};
int main()
{
    DoublyLinkedList *list = new DoublyLinkedList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);

    list->reverseBetween(1, 3);

    list->printList();
}
