#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap
{
//the mostly used when implementng Priorty Queue because of the complixity of adding or removing is o(log n)
//which its the hight of the tree  
private:
    vector<int> heap;
    int leftChild(int index)
    {
        return 2 * index + 1;
    }
    int rightChild(int index)
    {
        return 2 * index + 2;
    }
    int Parent(int index)
    {
        return (index - 1) / 2;
    }
    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    void sinkDown(int index)
    {

        int maxIndex = index;
        while (true)
        {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);
            if (leftIndex<heap.size()&&heap[leftIndex] > heap[rightIndex])
            {
                maxIndex = leftIndex;
            }
            if (rightIndex<heap.size()&&heap[leftIndex] < heap[rightIndex])
            {
                maxIndex = rightIndex;
            }
            if (maxIndex != index)
            {
                swap(index, maxIndex);
                index = maxIndex;
            }
            else
            {
                return;
            }
        }
    }

public:
    void printHeap()
    {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if (i < heap.size() - 1)
            {
                cout << " , ";
            }
        }
        cout << "]" << endl;
    }

    void insert(int value)
    {
        heap.push_back(value);
        int current = heap.size() - 1;
        while (current > 0 && heap[current] > heap[Parent(current)])
        {
            swap(current, Parent(current));
            current = Parent(current);
        }
    }
    int remove()
    {
        if (heap.empty())
        {
            return INT_MIN;
        }
        int MaxValue = heap.front();
        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }
        return MaxValue;
    }
};

int main()
{
    Heap *heap = new Heap();
    heap->insert(99);
    heap->insert(72);
    heap->insert(61);
    heap->insert(58);
    heap->printHeap();
    heap->insert(100);
    heap->printHeap();
    heap->insert(75);
    heap->printHeap();
}