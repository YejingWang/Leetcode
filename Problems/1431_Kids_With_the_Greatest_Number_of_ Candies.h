#pragma once

/* 
1431. Kids With the Greatest Number of Candies
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of candies among them. Notice that multiple kids can have the greatest number of candies.



Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]
Explanation:
Kid 1 has 2 candies and if he or she receives all extra candies (3) will have 5 candies --- the greatest number of candies among the kids.
Kid 2 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.
Kid 3 has 5 candies and this is already the greatest number of candies among the kids.
Kid 4 has 1 candy and even if he or she receives all extra candies will only have 4 candies.
Kid 5 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false]
Explanation: There is only 1 extra candy, therefore only kid 1 will have the greatest number of candies among the kids regardless of who takes the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]


Constraints:

2 <= candies.length <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50
*/

#include <vector>
#include <algorithm>

class Solution {
public:
	std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
		// 1.Use std::max_element
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		/*int max = *std::max_element(candies.begin(), candies.end());*/

		// 2.implement our own "max"
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		int max = 0;
		for (size_t i = 0; i < candies.size(); ++i) {
			max = candies[i] > max ? candies[i] : max;
		}

		std::vector<bool> res(candies.size());
		for (size_t i = 0; i < res.size(); ++i) {
			res[i] = (candies[i] + extraCandies >= max);
		}
		return res;
	}
};

/*
Tips:
	1.use std::max_element to find the largest element in range (returns an interator);
	2.std::max is not suitable for this problem
*/