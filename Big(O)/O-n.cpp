#include <iostream>

using namespace std;



void printItemsO(int n)  //o(n) droping the constant 
{
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
    for (int j = 0; j < n; j++) {
        cout << j << endl;
    }
}

void printItemsO2(int n)  //o(n^2) droping the constant 
{
    for (int i = 0; i < n; i++) {
        cout << i << endl;
        for (int j = 0; j < n; j++) {
            cout << j << endl;
        }
    }
}
void printItems(int n)  //o(n^2 + n) droping the non dominant  O(n^2)
{
    for (int i = 0; i < n; i++) {
        cout << i << endl;
        for (int j = 0; j < n; j++) {
            cout << j << endl;
        }
    }
    for (int k = 0; k < n; k++) {
        cout << k << endl;
    }
}




int main() { 

    printItemsO(10);

}

