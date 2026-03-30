#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int longestConsecutiveSequence(const vector<int> &nums)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds the longest consecutive       |
    //   |   sequence of integers in a given array.            |
    //   | - It uses an unordered_set for quick look-up.       |
    //   | - Loop through each unique number in the set.       |
    //   | - For each number, check its sequence length.       |
    //   | - Update 'longestStreak' if a longer sequence is    |
    //   |   found.                                            |
    //   |                                                     |
    //   | Return type: int                                    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'numSet' stores unique numbers from 'nums'.       |
    //   | - 'longestStreak' keeps track of the longest        |
    //   |   sequence found so far.                            |
    //   | - Use 'find' method for quick look-up in set.       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    // btklm 3 el keyboard hahahaha

    // first
    //  put the data of the array in  the set
    unordered_set<int> numSet(nums.begin(), nums.end());
    // //second
    // //order the set using Algorith libirary
    // //store it in a diffrent set???
    // sort(numSet.begin(),numSet.end());

    if(numSet.size()==0)
    {
        return 0;
    }


    int longestStreak = 0;
    for (int i : numSet)
    {
        if ((numSet.find(i - 1)) == numSet.end())
        {
            int currentStreak = 1;
            int currentNum = i;
            while (numSet.find(currentNum + 1) != numSet.end())
            {
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(currentStreak, longestStreak);
        }
    }
    return longestStreak;
}
int main()
{

    cout << longestConsecutiveSequence({1, 2, 3, 4});
}
