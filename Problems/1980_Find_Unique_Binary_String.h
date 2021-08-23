#pragma once

/* 
1980. Find Unique Binary String
https://leetcode.com/problems/find-unique-binary-string/

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.



Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.


Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
*/

#include <string>
#include <vector>

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        // 1. Convert to hex and store
        // Time complexity:     O(2^N)
        // Space complexity:    O(2^N)
        /*std::vector<int> v(std::pow(2, nums.size()), 0);
        for (auto str : nums) {
            int sum = 0;
            for (size_t i = 0; i < str.length(); ++i) {
                sum = 2 * sum + str[i] - '0';
            }
            v[sum] = 1;
        }
        std::string res(nums.size(), '0');
        for (size_t i = 0; i < v.size(); ++i) {
            if (v[i] == 0) {
                int j = res.size() - 1;
                while (i) {
                    if (i % 2) {
                        res[j] = '1';
                    }
                    --j;
                    i /= 2;
                }
                break;
            }
        }
        return res;*/

        // 2. Flip letters
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        std::string res(nums.size(), '0');
        for (size_t i = 0; i < nums.size(); ++i) {
            res[i] = '1' - (nums[i][i] - '0');
        }
        return res;
    }
};

/*
Tips:
*/