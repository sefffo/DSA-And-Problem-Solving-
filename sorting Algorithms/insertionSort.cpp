#include <iostream>
#include <vector>
using namespace std;
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}


//as we always start from the second item in the array to compare it with the item before it 
void insertionSort(int arr[],int size)
{
    for(int i = 1; i<size;i++)
    {
        int temp = arr[i];
        int j = i-1;
        while (j>-1&&temp<arr[j])
        {
            arr[j+1] = arr[j];
            arr[j]=temp;
            j--;
        }
        
    }
}