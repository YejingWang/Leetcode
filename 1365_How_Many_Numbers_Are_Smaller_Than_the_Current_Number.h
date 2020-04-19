#pragma once

/*
1365. How Many Numbers Are Smaller Than the Current Number
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.



Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation:
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1).
For nums[3]=2 there exist one smaller number than it (1).
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]


Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100
*/

#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
	std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
		// 1. count and sum
		// Time complexity:		O(N)
		// Space complexity:	O(N)
		/*std::map<int, int> cntMap;
		for (size_t i = 0; i < nums.size(); ++i) {
			++cntMap[nums[i]];
		}

		std::map<int, int> resMap;
		int prevCnt = 0;
		for (auto it = cntMap.begin(); it != cntMap.end(); ++it) {
			resMap[it->first] = prevCnt;
			prevCnt += it->second;
		}

		std::vector<int> res(nums.size());
		for (size_t i = 0; i < nums.size(); ++i) {
			res[i] = resMap[nums[i]];
		}

		return res;*/

		// 2. sort, count and sum
		// Time complexity:		O(N)
		// Space complexity:	O(N)
		std::vector<int> tmp(nums.begin(), nums.end());
		std::sort(tmp.begin(), tmp.end());
		int cnt = 0;
		int prevNum = -1;
		std::unordered_map<int, int> mp;
		for (size_t i = 0; i < tmp.size(); ++i) {
			if (tmp[i] != prevNum) {
				mp[prevNum] = cnt;
				prevNum = tmp[i];
				cnt = 1;
			}
			else {
				++cnt;
			}
		}
		mp[prevNum] = cnt;

		for (size_t i = 0; i < nums.size(); ++i) {
			tmp[i] = mp[nums[i]];
		}

		return tmp;
	}
};

/*
Tips:
	1.std::vector.insert(pos, n, val)
	2.std::vector.reserve() only changes the capacity() (not the size()) of the vector 
*/