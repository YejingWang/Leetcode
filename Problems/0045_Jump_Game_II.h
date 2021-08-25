#pragma once

/* 
45. Jump Game II
https://leetcode.com/problems/jump-game-ii/

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
*/

#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        // 1. Reverse dynamic programming
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        /*std::vector<int> dp(nums.size(), std::numeric_limits<int>::max());
        dp.back() = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= nums.size() - 1) {
                dp[i] = 1;
            }
            else {
                int curMin = std::numeric_limits<int>::max();
                for (size_t j = 1; j <= nums[i]; ++j) {
                    curMin = std::min(curMin, 1 + dp[i + j]);
                }
                dp[i] = curMin;
            }
        }
        return dp.front();*/

        // 2. Greedy
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int jumps = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            curFarthest = std::max(curFarthest, i + nums[i]);
            if (i == curEnd) {
                ++jumps;
                curEnd = curFarthest;
                if (curEnd >= nums.size() - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};

/*
Tips:
*/