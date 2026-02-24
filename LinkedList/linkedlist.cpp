#include <iostream> // Input/output
#include <vector>    // Dynamic arrays
#include <list>      // Linked lists
#include <algorithm> // Algorithms (sort, find, etc.)
#include <memory>    // Smart pointers
#include <string> // String class
#include <limits>    // Numeric limits

using namespace std;

// Node structure for linked list
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
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
        head = newNode; // the variable head points to the first node
        tail = newNode;
        length = 1;
    }
    ~LinkedList() // Destructor to free memory allocated for the linked list
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void PrintList() // o(n) time complexity and o(1) space complexity
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
    }
    void getHead() // o(1) time complexity and o(1) space complexity
    {
        if (head != nullptr)
        {
            cout << "Head: " << head->value << endl;
        }
        else
        {
            cout << "The list is empty." << endl;
        }
    }
    void getTail() // o(1) time complexity and o(1) space complexity
    {
        if (tail != nullptr)
        {
            cout << "Tail: " << tail->value << endl;
        }
        else
        {
            cout << "The list is empty." << endl;
        }
    }
    void getLength() // o(1) time complexity and o(1) space complexity
    {
        cout << "Length: " << length << endl;
    }
    void append(int val) // o(1) time complexity and o(1) space complexity
    {
        Node *newNode = new Node(val);
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
    void appendWithTemp(int val) // o(n) time complexity and o(1) space complexity , // create append but using temp variable to traverse the list
    {
        Node *newNode = new Node(val);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void DeletLast()// o(n) time complexity and o(1) space complexity
    {
        if (length == 0)
        {
            cout << "The List is Empty" << endl;
        }
        else if (length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = head;
            Node *pre = head;
            while (temp->next != nullptr)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
            delete temp;
        }
        length--;
    }
    void prepend(int val)// o(1) time complexity and o(1) space complexity
    {
        Node *newNode = new  Node(val);
        if(length == 0){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
            length++;
        }
        length++;
    }
    void DeleteFirst()// o(1) time complexity and o(1) space complexity
    {
        if(length == 0){
            cout << "The List is Empty" << endl;
        }else if(length == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
        }else{
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        length--;
    }
    Node* get(int index) // o(n) time complexity and o(1) space complexity
    {
        if(length == 0 || index < 0 || index >= length){
            return nullptr;
        }
        Node *temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp;
    }
    bool set(int index, int value) // o(n) time complexity and o(1) space complexity
    {
        Node *temp = get(index);
        if(temp != nullptr){
            temp->value = value;
            return true;
        }
        return false;
    }
    void insert(int index, int value) // o(n) time complexity and o(1) space complexity
    {
        if(index < 0 || index > length){
            return ;
        }
        if(index == 0){
            prepend(value);
            return ;
        }
        if(index == length){
            append(value);
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
    void remove(int index) // o(n) time complexity and o(1) space complexity
    {
        if(index < 0 || index >= length){
            return ;
        }
        if(index == 0){
            DeleteFirst();
            return ;
        }
        if(index == length - 1){
            DeletLast();
            return;
        }
        Node *temp = head;
        Node *pre = head;
        for(int i = 0; i < index - 1; i++){
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        delete temp;
        length--;
    }
    void reverse() //o(n) time complexity and o(1) space complexity
    {
        Node *temp = head;
        head = tail;
        tail = temp;
        Node *before = nullptr;
        Node *after = nullptr;
        for(int i = 0; i < length; i++){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }
};

int main()
{
    
    return 0;
}