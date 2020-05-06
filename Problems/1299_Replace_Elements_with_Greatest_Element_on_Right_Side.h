#pragma once

/* 
1299. Replace Elements with Greatest Element on Right Side
https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.



Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]


Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/

#include <vector>
#include <algorithm>

class Solution {
public:
	std::vector<int> replaceElements(std::vector<int>& arr) {
		// 1. Traverse backwards and keep track of the max
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		/*int max = arr.back();
		int tmp = -1;
		for (int i = arr.size() - 1; i >= 0; --i) {
			tmp = max;

			if (arr[i] > max) {
				max = arr[i];
			}
			if (i == arr.size() - 1) {
				arr[i] = -1;
			}
			else {
				arr[i] = tmp;
			}
		}*/

		// 2. Use std::exchange()
		// Time complexity:		O(N)
		// Space complexity:	O(1)
		int max = -1;
		for (int i = arr.size() - 1; i >= 0; --i) {
			max = std::max(max, std::exchange(arr[i], max));
		}

		return arr;
	}
};

/*
Tips:
	1. Make sure i is an int instead of a size_i/unsigned int when --i is used
	2.T std::exchange(T& val, T& new_val) assigns new_val to val and returns val
*/