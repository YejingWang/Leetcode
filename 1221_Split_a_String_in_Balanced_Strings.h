#pragma once

/*
1221. Split a String in Balanced Strings
https://leetcode.com/problems/split-a-string-in-balanced-strings/

Balanced strings are those who have equal quantity of 'L' and 'R' characters.

Given a balanced string s split it in the maximum amount of balanced strings.

Return the maximum amount of splitted balanced strings.



Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
Example 4:

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'


Constraints:

1 <= s.length <= 1000
s[i] = 'L' or 'R'
*/

#include <string>

class Solution {
public:
	int balancedStringSplit(std::string s) {
		// 1. greedy search
		// Time complexity:     O(N)
		// Space complexity:    O(1)
		/*int cnt = 0, lCnt = 0, rCnt = 0;
		for (char& c : s) {
			if (c == 'L') {
				++lCnt;
			}
			else {
				++rCnt;
			}
			if (lCnt == rCnt) {
				++cnt;
				lCnt = 0;
				rCnt = 0;
			}
		}*/

		// 2. better greedy search
		// Time complexity:     O(N)
		// Space complexity:    O(1)
		int cnt = 0, charCnt = 0;
		for (char& c : s) {
			if (c == 'L') {
				++charCnt;
			}
			else {
				--charCnt;
			}
			if (charCnt == 0) {
				++cnt;
			}
		}

		return cnt;
	}
};

/*
Tips:
	1. since each char is either L or R, we can use one variable to take count
*/