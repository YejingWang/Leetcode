#pragma once

/* 
1295. Find Numbers with Even Number of Digits
https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

Given an array nums of integers, return how many of them contain an even number of digits.


Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation:
12 contains 2 digits (even number of digits).
345 contains 3 digits (odd number of digits).
2 contains 1 digit (odd number of digits).
6 contains 1 digit (odd number of digits).
7896 contains 4 digits (even number of digits).
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1
Explanation:
Only 1771 contains an even number of digits.


Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 10^5
*/

#include <vector>
#include <string>

class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int res = 0;

        // 1.
        // Time complexity:     O(N * L)
        // Space complexity:    O(1)
        for (size_t i = 0; i < nums.size(); ++i) {
            int digits = 0;
            while (nums[i] != 0) {
                nums[i] /= 10;
                ++digits;
            }
            if (digits % 2 == 0) {
                ++res;
            }
        }

        // 2.
        // Time complexity:     ?
        // Space complexity:    O(1)
        /*for (size_t i = 0; i < nums.size(); ++i) {
            std::string str = std::to_string(nums[i]);
            if (str.length() % 2  == 0) {
                ++res;
            }
        }*/

        return res;
    }
};

/*
Tips:
	1.the first solution is faster
	2.we don't know the time complexity of std::to_string
*/