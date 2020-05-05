#pragma once

/* 
1304. Find N Unique Integers Sum up to Zero
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

Given an integer n, return any array containing n unique integers such that they add up to 0.



Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]


Constraints:

1 <= n <= 1000

*/

#include <vector>

class Solution {
public:
	std::vector<int> sumZero(int n) {
		// 1.simple math
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		std::vector<int> res;
		if (n % 2 != 0) {
			res.push_back(0);
		}
		for (int i = 1; i <= n / 2; ++i) {
			res.push_back(-i);
			res.push_back(i);
		}
		return res;
	}
};

/*
Tips:
*/