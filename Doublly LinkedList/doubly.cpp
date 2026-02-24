#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

// doubly linked list

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
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
    void PrintList() // O(n)
    {
        Node *temp = head;
        if (length == 0)
        {
            cout << "List is Empty" << endl;
        }
        while (temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void GetHead() // O(1)
    {
        cout << "Head : " << head->data << endl;
    }
    void append(int val) // O(1)
    {
        Node *newNode = new Node(val);
        if (length == 0)
        {
            head = tail = newNode;
        }
        else
        {

            newNode->next = nullptr;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        length++;
    }
    void DeleteLast()
    {
        if (length == 0)
        {
            return;
        }
        Node *temp = tail;
        if (length == 1)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete (temp); // bara 3shan myms7sh el node el abl el akhira
        length--;
    }
    void Prepend(int val) // O(1)
    {
        Node *newNode = new Node(val);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            newNode->prev = nullptr;
        }
        length++;
    }
    void DeleteFirst() // O(1)
    {
        if (length = 0)
            return;
        Node *temp = head;
        if (length = 1)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }
    Node *Get(int index) // O(N)
    {
        if (length == 0 || index < 0 || index >= length)
        {
            return nullptr;
        }
        // with ptimization
        Node *temp = head;
        if (index < (length / 2))
        {

            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        return temp;
    }
    bool set(int index, int val) // O(N)
    {
        Node *temp = Get(index);
        if (temp)
        {
            temp->data = val;
            return true;
        }
        return false;
    }
    bool insert(int index, int val)
    {
        // if(index<0 || index>length)//O(N)
        // {
        //     return ;
        // }
        // if(index==0)
        // {
        //     Prepend(val);
        //     return ;
        // }
        // if(index==length)
        // {
        //     append(val);
        //     return ;
        // }
        // Node *newNode = new Node(val);
        // Node *temp = head;
        // for(int i=0;i<index-1;i++)
        // {
        //     temp = temp->next;
        // }
        // temp->next->prev = newNode;
        // newNode->next = temp->next;
        // temp->next = newNode;
        // newNode->prev = temp;
        // length++;

        if (index < 0 || index > length) // o(n/2) ==>both are almost the same
        {
            return false;
        }
        if (index == 0)
        {
            Prepend(val);
            return true;
        }
        if (index == length)
        {
            append(val);
            return true;
        }
        Node *newNode = new Node(val);
        Node *before = Get(index - 1);
        Node *after = before->next;
        after->prev = newNode;
        // this how we insert
        newNode->next = after;
        newNode->prev = before;
        before->next = newNode;
        length++;
        return true;
    }
    void Delete(int index)
    {

        if (index < 0 || index >= length)
            return;
        if (index == 0)
            return DeleteFirst();
        if (index == length)
            return DeleteLast();

        Node *temp = Get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    }
    void GetTail() // O(1)
    {
        cout << "Tail : " << tail->data << endl;
    }
    void GetLength() // O(1)
    {
        cout << "Length : " << length << endl;
    }
};

int main()
{
    DoublyLinkedList *list = new DoublyLinkedList(1);
    

    return 0;
}
