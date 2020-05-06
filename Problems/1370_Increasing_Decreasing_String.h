#pragma once

/* 
1370. Increasing Decreasing String
https://leetcode.com/problems/increasing-decreasing-string/

Given a string s. You should re-order the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.



Example 1:

Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
Example 2:

Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
Example 3:

Input: s = "leetcode"
Output: "cdelotee"
Example 4:

Input: s = "ggggggg"
Output: "ggggggg"
*/

#include <string>

class Solution {
public:
	std::string sortString(std::string s) {
		// 1.Use std::map and go through steps in the given algorithms
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		/*std::string res;
		std::map<char, int> mp;
		for (char& c : s) {
			++mp[c];
		}
		int cnt = s.size();
		while (cnt > 0) {
			for (auto it = mp.begin(); it != mp.end(); ++it) {
				if (it->second > 0) {
					res += it->first;
					--it->second;
					--cnt;
				}
			}
			for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
				if (it->second > 0) {
					res += it->first;
					--it->second;
					--cnt;
				}
			}
		}
		return res;*/

		// 2.Use int[] and go through steps in the given algorithms; preallocate the size of s
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		std::string res(s.size(), 'A');
		int mp[26] = { 0 };
		for (char& c : s) {
			++mp[c - 'a'];
		}
		int pos = 0;
		while (pos < s.size()) {
			for (int i = 0; i < 26; ++i) {
				if (mp[i] > 0) {
					res[pos] = (i + 'a');
					--mp[i];
					++pos;
				}
			}
			for (int i = 25; i >= 0; --i) {
				if (mp[i] > 0) {
					res[pos] = (i + 'a');
					--mp[i];
					++pos;
				}
			}
		}
		return res;
	}
};

/*
Tips:
	1.use int[] instead of map when we know the size of input
	2.std::string can be initialized with string (size_t n, char c); n in the front!
*/