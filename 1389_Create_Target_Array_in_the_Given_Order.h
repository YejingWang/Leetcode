#pragma once

/*
1389. Create Target Array in the Given Order
https://leetcode.com/problems/create-target-array-in-the-given-order/

Given two arrays of integers nums and index. Your task is to create target array under the following rules:

Initially target array is empty.
From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.

It is guaranteed that the insertion operations will be valid.



Example 1:

Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
Example 2:

Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
Output: [0,1,2,3,4]
Explanation:
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]
Example 3:

Input: nums = [1], index = [0]
Output: [1]


Constraints:

1 <= nums.length, index.length <= 100
nums.length == index.length
0 <= nums[i] <= 100
0 <= index[i] <= i
*/

#include <vector>

class Solution {
public:
	std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
		std::vector<int> target;

		// 1.use std::vector.insert()
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		for (size_t i = 0; i < nums.size(); ++i) {
			auto it = target.begin();
			target.insert(it + index[i], nums[i]);
		}

		// 2. insert manually
		// TO-DO: Suppose the intputs are two int[]

		return target;
	}
};

/*
Tips:
	1.can use fixed-size arrays when we know the upper bound
	2.int arr[n] = { val } can be used to initialize an array with n same values
*/