#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> twoSum(const vector<int> &nums, int target)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds two numbers in 'nums' that    |
    //   |   sum up to the given 'target'.                     |
    //   | - It uses an unordered_map for quick look-up.       |
    //   | - It returns the indices of the numbers that add    |
    //   |   up to the target.                                 |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'numMap' stores numbers and their indices.        |
    //   | - 'complement' is the value needed to reach target. |
    //   | - Use 'find' method for quick look-up in map.       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    unordered_map<int, int> numMap;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (numMap.count(complement))
        {

            return {numMap[complement], i};
        }
        numMap.insert({nums[i], i});
    }

    return res;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5, 6};

    vector<int> nums = {1, 2, 3, 4, 5, 6};
    twoSum(nums, 6);

    vector<int> result = twoSum(nums, 6);

    for (auto i : result)
    {
        cout << i << " ";
    }
}