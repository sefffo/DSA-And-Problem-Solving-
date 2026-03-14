#include<iostream>
using namespace std;


int factorial(int val)
{
    if(val == 1)
    {
        return 1 ;
    }
    return val*factorial(val-1);
}

int main()
{

    cout<<factorial(5);






    return 0;
}
