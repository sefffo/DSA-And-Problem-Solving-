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
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[MinIndex])
            {
                MinIndex = j;
            }
        }
        if (i != MinIndex)
        {
            swap(arr[i], arr[MinIndex]);
        }   
    }
}
int main()
{
    int arr[] = {5,2,3,4,8,9};

    int size = sizeof(arr)/ sizeof(arr[0]);

    selectionSort(arr,size);

    for(int i : arr)
    {
        cout<<i;
    }

}