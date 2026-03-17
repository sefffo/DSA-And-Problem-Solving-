#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

struct Node
{
    Node *next;
    string key;
    int value;
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

public:
    void printTable() // O(N^2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " : " << endl;

            if (dataMap[i])
            {
                Node *temp = dataMap[i];
                while (temp)
                {

                    cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }

    int hash(string key) // o(k : string chars )
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) // ittrate over the letters to get te ascii val
        {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE; // to make the hashing random and the % to make it between 0~6
        }
        return hash;
    }

    void set(string key, int value)
    {
        int index = hash(key); // address the node will go
        Node *newNode = new Node(key, value);
        if (dataMap[index] == nullptr)
        {
            dataMap[index] = newNode;
        }
        else
        {
            Node *temp = dataMap[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int Get(string key)
    {
        int index = hash(key);
        Node *temp = dataMap[index]; // holding pointers to the nodes we have ,
                                     // so if therse is a index have no nodes temp == nullptr
        while (temp != nullptr)
        {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return 0;
    }

    vector<string> Keys()
    {
        vector<string> allkeys;
        for (int i = 0; i < SIZE; i++)
        {
            Node *temp = dataMap[i];
            while (temp != nullptr)
            {
                allkeys.push_back(temp->key);
                temp = temp->next;
            }
        }

        return allkeys;
    }
};

int main()
{
    HashTable *table = new HashTable();
    // table->printTable();

    table->set("nails", 100);
    table->set("hardware", 300);
    table->set("saif", 1000);
    table->set("omar", 1000);

    table->printTable();

    cout << endl;

    cout << "Saif : " << table->Get("saif") << endl;
    ;
    cout << "Lotfy : " << table->Get("lotfy") << endl;

    vector<string> mykeys = table->Keys();

    for (auto key : mykeys)
    {
        cout << key << " ";
    }
}

bool itemInCommon(vector<int> vec1, vector<int> vec2)
{
    unordered_map<int, bool> map;
    for (auto i : vec1)
    {
        map.insert({i, true});
    }
    for (auto j : vec2)
    {
        if (map[j])
        {
            return true;
        }
    }
    return false;
}