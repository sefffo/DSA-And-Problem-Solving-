#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> subarraySum(const vector<int> &nums, int target)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds a subarray in 'nums' that     |
    //   |   sums up to the given 'target'.                    |
    //   | - It uses an unordered_map for quick look-up.       |
    //   | - It returns the indices of the start and end       |
    //   |   elements of the subarray.                         |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'sumIndex' stores cumulative sums and their       |
    //   |   indices.                                          |
    //   | - 'currentSum' keeps track of the sum up to index i.|
    //   | - Use 'find' method for quick look-up in map.       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    unordered_map<int, int> sumIndex;
    vector<int> res;

    sumIndex.insert({0, -1});

    int cumulative = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cumulative += nums[i];

        int currSum = cumulative - target;
        // sumIndex.find(currSum);
        auto it = sumIndex.find(currSum);
        if (it != sumIndex.end()) // ← "did we actually find something?"
        {
            // it->second = the index stored in the map
            
            return {it->second + 1, i};
        }
        else
        {
            // not found → insert current cumulative
            sumIndex.insert({cumulative,i});
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 9;

    vector<int> result = subarraySum(nums, target);

    for(auto i : result)
    {
        cout << i << " ";
    }
}
