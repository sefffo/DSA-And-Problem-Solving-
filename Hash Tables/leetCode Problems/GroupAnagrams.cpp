#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string> &strings)
{
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function groups anagrams from a given vector |
    //   |   of strings.                                       |
    //   | - It uses an unordered_map for organization.        |
    //   | - It sorts each string to form a canonical version. |
    //   | - Groups strings with the same canonical form.      |
    //   |                                                     |
    //   | Return type: vector<vector<string>>                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'anagramGroups' maps canonical strings to groups. |
    //   | - 'canonical' is a sorted version of each string.   |
    //   | - 'result' holds the final groups of anagrams.      |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    unordered_map<string, vector<string>> anagramGroups;
    // vector<string> canonical;

    for (auto i : strings)
    {
        string sortedStr = i;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(i); // el key hwa el [sortedStr] we el values hya el i
    }

    vector<vector<string>> res;
    for (auto i : anagramGroups)
    {

        res.push_back(i.second);
    }

    return res;
}

int main()
{
    vector<string> strings = {"eat", "tea", "tan", "ate", "nat", "bat"};

    auto ans = groupAnagrams(strings);
    for (auto i : ans)
    {
        for (auto str : i)
        {
            cout << str << " "; // space between words in the same group
        }
        cout << "\n"; // new line between groups
    }
}