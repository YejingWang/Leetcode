#pragma once

/* 
1512. Number of Good Pairs
https://leetcode.com/problems/number-of-good-pairs/

Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.



Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0


Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int res = 0;

        // 1.Brute force
        // Time complexity:     O(N^2)
        // Space complexity:    o(1)
        /*for (size_t i = 0; i < nums.size() - 1; ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    ++res;
                }
            }
        }*/

        // 2.Map
        // Time complexity:     O(N)
        // Space complexity:    o(N)
        /*std::unordered_map<int, int> mp;
        for (size_t i = 0; i < nums.size(); ++i) {
            ++mp[nums[i]];
        }

        for (auto& p : mp) {
            res += p.second * (p.second - 1) / 2;
        }*/

        // 3.Array
        // Time complexity:     O(N)
        // Space complexity:    o(N)
        /*int mp[1000]{0};
        for (size_t i = 0; i < nums.size(); ++i) {
            ++mp[nums[i]];
        }

        for (int i = 0; i < 100; ++i) {
            res += mp[i] * (mp[i] - 1) / 2;
        }*/

        // 4.Simpler map
        // Time complexity:     O(N)
        // Space complexity:    o(N)
        std::unordered_map<int, int> mp;
        for (size_t i = 0; i < nums.size(); ++i) {
            res += mp[nums[i]]++;
        }

        return res;
    }
};

/*
Tips:
*/