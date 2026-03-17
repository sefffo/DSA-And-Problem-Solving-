#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

char firstNonRepeatingChar(const string &input_string)
{
	//   +======================================================+
	//   |                 WRITE YOUR CODE HERE                 |
	//   | Description:                                         |
	//   | - This function finds the first non-repeating char   |
	//   |   in a given string.                                 |
	//   | - It uses an unordered_map to count char occurrences |
	//   | - Loops through the string to check counts.          |
	//   |                                                      |
	//   | Return type: char                                    |
	//   |                                                      |
	//   | Tips:                                                |
	//   | - 'charCounts' keeps track of each char's count.     |
	//   | - Loops twice: once to count, once to find answer.   |
	//   | - Returns '\0' if no non-repeating char is found.    |
	//   | - Check output from Test.cpp in "User logs".         |
	//   +======================================================+
	unordered_map<char, int> charCounts;
	for (auto i : input_string)
	{
		charCounts[i]++;
	}

	for (auto i : input_string)
	{

		if(charCounts[i] == 1)
		{
			return i;
		}
	}
	return '\0';
}

int main()
{
	string s = "saaif";

	cout<<firstNonRepeatingChar(s);
}