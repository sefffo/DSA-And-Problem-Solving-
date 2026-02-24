#include <iostream>
using namespace std;
// LIFO
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Stack
{
private:
    Node *top;
    int height;

public:
    Stack(int val)
    {
        Node *newNode = new Node(val);
        top = newNode;
        height = 1;
    };
    ~Stack()
    {
        Node *temp = top;
        while (top)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    };

    void printStack()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void getTop()
    {
        cout << "Top : " << top->data << endl;
    }

    void getHeight()
    {
        cout << "Height : " << height << endl;
    }

    void push(int val) // o(1) time complexity and o(1) space complexity
    {
        Node *newNode = new Node(val);
        // beacuse we dont have a tail we dont need if/else
        newNode->next = top;
        top = newNode;
        height++;
    }
    int pop() // o(1) time complexity and o(1) space complexity
    {
        if (height == 0)
        {
            cout << "The List is Empty" << endl;
            return INT_MIN; // because i never expect that
        }
        Node *temp = top;
        int popedVal = top->data;
        top = top->next;
        delete temp;
        height--;
        return popedVal;
    }
};

// Queue FIFO

class Queue
{
private:
    int length;
    Node *first;
    Node *last;

public:
    Queue(int val)
    {
        Node *newNode = new Node(val);
        this->first = newNode;
        this->last = newNode;
        length = 1;
    }
    ~Queue()
    {
        Node *temp = first;
        while (first)
        {
            first = first->next;
            delete temp;
            temp = first;
        }
    }

    void GetFirst()
    {
        cout << "First : " << first->data << endl;
    }
    void GetLast()
    {
        cout << "Last : " << last->data << endl;
    }

    void GetLength()
    {
        cout << "Length : " << length << endl;
    }

    void printQueue()
    {
        Node *temp = first;
        while (temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void Enqueue(int val) // o(1) time complexity and o(1) space complexity
    {
        Node *newNode = new Node(val);
        if (length == 0)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    int Dequeue() // o(1) time complexity and o(1) space complexity
    {
        if (length == 0)
        {
            cout << "The List is Empty" << endl;
            return INT_MIN; // because i never expect that
        }
        Node *temp = first;
        int dequeuedVal = first->data;
        if (length == 1)
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = first->next;
        }
        delete temp;
        length--;
        return dequeuedVal;
    }
};

int main()
{
    // Stack *myStack = new Stack(1);
    // myStack->push(2);
    // myStack->push(3);
    // myStack->push(4);
    // myStack->printStack();
    // cout << "Popped : " << myStack->pop() << endl;
    // myStack->printStack();
    // delete myStack;

    Queue *myQueue = new Queue(1);
    myQueue->Enqueue(2);
    myQueue->Enqueue(3);
    myQueue->Enqueue(4);
    myQueue->printQueue();
    cout << "Dequeued : " << myQueue->Dequeue() << endl;
    myQueue->printQueue();
    // delete myQueue;

    return 0;
}