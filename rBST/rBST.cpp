#include <iostream>
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

    int MinValue(Node *currentNode)
    {
        while (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }

        return currentNode->value;
    }






    Node *rDeleteNode(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return nullptr; // value not in the tree

        if (value < currentNode->value)
        {
            currentNode->left = rDeleteNode(currentNode->left, value);
        }
        else if (value > currentNode->value)
        {
            currentNode->right = rDeleteNode(currentNode->right, value);
        }
        else
        {
            if (currentNode->right == nullptr && currentNode->left == nullptr)
            {
                delete (currentNode);
                return nullptr;
            }
            else if (currentNode->right == nullptr)
            {
                Node *temp = currentNode->left;
                delete (currentNode);
                return temp;
            }
            else if (currentNode->left == nullptr)
            {
                Node *temp = currentNode->right;
                delete (currentNode);
                return temp;
            }
            else
            {
                auto minSubtreeNode= MinValue(currentNode->right);
                currentNode->value = minSubtreeNode;
                currentNode->right=rDeleteNode(currentNode->right , minSubtreeNode);
            }
        }
        return currentNode;
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

        Node *rInsert(Node * CurrentNode, int value)
        {
            if (CurrentNode == nullptr)
                return new Node(value);

            if (value < CurrentNode->value)
            {
                CurrentNode->left = rInsert(CurrentNode->left, value);
            }
            else if (value > CurrentNode->value)
            {
                CurrentNode->right = rInsert(CurrentNode->right, value);
            }
            return CurrentNode;
        }

        void rInsert(int value)
        {
            if (root == nullptr)
            {
                /* code */
                root = new Node(value);
                rInsert(root, value);
            }
        }

        bool rContains(Node * CurrentNode, int value)
        {
            if (CurrentNode == nullptr)
                return false;
            if (CurrentNode->value == value)
                return true;

            if (value < CurrentNode->value)
            {
                return rContains(CurrentNode->left, value);
            }
            else
            {
                return rContains(CurrentNode->right, value);
            }
        }

        bool rContains(int value)
        {
            rContains(root, value);
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

        cout << (bst->root->left->right)->value << endl;

        cout << (bst->Conatins(27)) << endl;
        cout << (bst->Conatins(17)) << endl;
    }