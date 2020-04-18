#pragma once

/* 
771. Jewels and Stones
https://leetcode.com/problems/jewels-and-stones/

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/

#include <string>

class Solution {
public:
	int numJewelsInStones(std::string J, std::string S) {
		int count = 0;

		// 1. Traversal
		// Time complexity:		O(j * s)
		// Space complexity:	O(1)
		/*for (char s : S)
		{
			for (char j : J)
			{
				if (s == j)
					++count;
			}
		}*/

		// 2. Better traversal
		// Time complexity:		O(j * s)
		// Space complexity:	O(1)
		/*for (char j : J)
		{
			for (char s : S)
			{
				if (s == j)
					++count;
			}
		}*/

		// 3. Betterer traversal
		// Time complexity:		O(lg(j) * s) ?
		// Space complexity:	O(1)
		for (char& s : S) {
			if (std::find(J.begin(), J.end(), s) != J.end()) {
				++count;
			}
		}

		// 4. Use unordered_set
		// Time complexity:		O(j + s)
		// Space complexity:	O(j)
		/*std::unordered_set<char> jSet(J.begin(), J.end());
		for (char s : S)
		{
			if (jSet.count(s))
				count++;
		}*/

		return count;
	}
};

/*
Tips:
	1.std::unordered_set can be constructed with two iterators (range), O(N) in time
	2.std::unordered_set.count() is O(1) in time
*/