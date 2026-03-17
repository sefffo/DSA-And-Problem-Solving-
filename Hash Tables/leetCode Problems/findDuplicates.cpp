#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> findDuplicates(const vector<int> &nums)
{
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function finds duplicate integers in a given |
	//   |   vector.                                           |
	//   | - It uses an unordered_map to count each integer's  |
	//   |   occurrences.                                      |
	//   | - Loops through the map to find duplicates.         |
	//   |                                                     |
	//   | Return type: vector<int>                            |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'numCounts' keeps track of each integer's count.  |
	//   | - 'duplicates' stores duplicate integers found.     |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+

	unordered_map<int, int> numCount; // acts like freq array

	vector<int> dups;

	for (auto i : nums)
	{
		numCount[i]++;
	}

	for (auto i : numCount)
	{
		if (i.second > 1)
		{
			dups.push_back(i.first);
		}
	}

	return dups;
}

int main()
{
	vector<int> nums = {1, 2, 1, 2, 6, 2, 4, 1};
	

	auto vec =  findDuplicates(nums);

	for(auto i : vec)
	{
		cout<<i;
	}
}