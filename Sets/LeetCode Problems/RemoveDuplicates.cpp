// #include "RemoveDuplicates.h"
#include<string>
#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;


vector<int> removeDuplicates(const vector<int>& myList) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function removes duplicate integers from a   |
    //   |   given vector 'myList'.                            |
    //   | - It uses an unordered_set for quick look-up and    |
    //   |   elimination of duplicates.                        |
    //   | - Returns a vector of unique integers.              |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'uniqueSet' stores unique numbers from 'myList'.  |
    //   | - Use 'begin()' and 'end()' to copy elements back   |
    //   |   to a vector.                                      |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+


    unordered_set<int> mySet ={};

    for(int i : myList)
    {
        mySet.insert(i);
    }


    vector<int> newList;
    for(int j : mySet)
    {
        newList.push_back(j);
    }

    return newList;





}