#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
private:
    // key    value
    unordered_map<string, unordered_set<string>> adjList; // for creating the adjecent list
public:
    bool addVertex(string vertex)
    {

        if (adjList.count(vertex) == 0) // check if it already in the list or not
        {
            adjList[vertex];
            return true;
        }
        return false;
    }

    void printGraph()
    {
        for (auto [vertex, edges] : adjList)
        {
            cout << vertex << " : [ ";
            for (auto edge : edges)
            {
                cout << edge << " , ";
            }
            cout << "]" << endl;
        }
    }

    bool AddEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }
    bool RemoveEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }
    bool RemoveVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)
            return false;

        for (auto otherVertex : adjList.at(vertex))
        {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }
};

int main()
{

    Graph *g = new Graph();

    g->addVertex("A");
    g->addVertex("B");
    g->addVertex("C");
    g->AddEdge("A", "B");
    g->AddEdge("A", "C");
    g->AddEdge("B", "C");
    g->printGraph();
    cout << "------------------" << endl;
    g->RemoveVertex("A");
    g->printGraph();
}