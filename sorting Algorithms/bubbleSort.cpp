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
void bubbleSort(vector<int> &list)
{
    for(int i =0 ; i < list.size();i++)
    {
        for(int j = 0; j<list.size()-i-1;j++)
        {
            if(list[j]>list[j+1])
            {
                swap(list[j],list[j+1]);
            }
        }
    }
}
int main()
{
    vector<int> v = {4,8,6,4,1,2,3,10,9};

    bubbleSort(v);

    for(int i : v)
    {
        cout<<i;
    }
}