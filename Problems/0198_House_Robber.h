#pragma once

/* 
198. House Robber
https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        // 1. Ill-formed DP
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::max(nums[0], nums[1]);
        if (nums.size() == 3) return std::max(nums[0] + nums[2], nums[1]);
        int size = nums.size();
        std::vector<int> v(size);
        v[0] = nums[0];
        v[1] = nums[1];
        v[2] = nums[0] + nums[2];
        for (size_t i = 3; i < size; ++i) {
            v[i] = nums[i] + std::max(v[i-2], v[i-3]);
        }
        return std::max(v[size - 1], v[size - 2]);*/

        // 2. DP
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        if (nums.size() == 0) return 0;
        int p = 0;
        int q = 0;
        for (auto num : nums) {
            int tmp = p;
            p = std::max(q + num, p);
            q = tmp;
        }
        return p;
    }
};

/*
Tips:
*/