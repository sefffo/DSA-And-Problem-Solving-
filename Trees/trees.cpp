#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
    Node *left;
    Node *right;
    int value;

public:
    Node(int val)
    {
        this->value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

public:
    BinarySearchTree()
    {
        root = nullptr;
        // we will create that new node with the Insert
    }

    void destroy(Node *currentNode)
    {
        if (currentNode == nullptr)
            return;
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    bool Insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }

        Node *temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
            {
                return false;
            }
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
    bool Conatins(int value)
    {
        if (root == nullptr)
            return false;
        Node *temp = root;
        while (temp)
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    
    
    
    void BFS()
    {
        queue<Node *> myQueue;
        myQueue.push(root);
        while (myQueue.size() > 0)
        {
            Node *CurrentNode = myQueue.front();
            myQueue.pop();
            cout<< CurrentNode->value<<" ";
            if(CurrentNode->left)
            {
                myQueue.push(CurrentNode->left);
            }  
            if(CurrentNode->right)
            {
                myQueue.push(CurrentNode->right);
            }
        }
    }


    void DFSPreOrder(Node *currentNode)
    {
        cout<<currentNode->value<<" ";
        if(currentNode->left)
        {
            DFSPreOrder(currentNode->left);
        }
        if(currentNode->right)
        {
            DFSPreOrder(currentNode->right);
        }
    }
    void DFSPreOrder()
    {
        DFSPreOrder(root);
    }
    void DFSPostOrder(Node*currentNode)
    {
        if(currentNode->left)
        {
            DFSPreOrder(currentNode->left);
        }
        if(currentNode->right)
        {
            DFSPreOrder(currentNode->right);
        }
        cout<<currentNode->value<<" ";
    }
    void DFSPostOrder()
    {
        DFSPostOrder(root);
    }
    void DFSInOrder(Node*currentNode)
    {
        if(currentNode->left)
        {
            DFSPreOrder(currentNode->left);
        }
        cout<<currentNode->value<<" ";
        if(currentNode->right)
        {
            DFSPreOrder(currentNode->right);
        }
    }
    void DFSInOrder()
    {
        DFSInOrder(root);
    }
};

int main()
{
    BinarySearchTree *bst = new BinarySearchTree();

    bst->Insert(47);
    bst->Insert(21);
    bst->Insert(76);
    bst->Insert(18);
    bst->Insert(52);
    bst->Insert(82);

    bst->Insert(27);

    // cout << (bst->root->left->right)->value << endl;

    // cout << (bst->Conatins(27)) << endl;
    // cout << (bst->Conatins(17)) << endl;

    // bst->BFS();
    bst->DFSPreOrder();
}