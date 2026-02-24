#include <iostream>

using namespace std;

int main()
{
    int *j = new int(1);

    int *s = j;

    *j = 2;
    cout << *s << " " << *j << endl;
}