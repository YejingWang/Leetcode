#pragma once

/* 
55. Jump Game
https://leetcode.com/problems/jump-game/

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    bool jump(std::vector<int>& nums, int start) {
        if (start + nums[start] >= nums.size() - 1) return true;
        for (int i = 1; i <= nums[start]; ++i) {
            if (jump(nums, start + i)) {
                return true;
            }
        }
        return false;
    }

    bool canJump(std::vector<int>& nums) {
        // 1. Recursion (TLE)
        // Time complexity:     O(N^N)
        // Space complexity:    O(N)
        //return jump(nums, 0);

        // 2. Reverse dynamic programming
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        /*std::vector<bool> dp(nums.size(), false);
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i + nums[i] >= nums.size() - 1) {
                dp[i] = true;
            }
            else {
                for (int j = 1; j <= nums[i]; ++j) {
                    if (dp[i + j]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];*/

        // 3. In-place dynamic programming
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        /*for (int i = nums.size() - 1; i >= 0; --i) {
            if (i + nums[i] >= nums.size() - 1) {
                nums[i] = -nums[i];
            }
            else {
                for (int j = 1; j <= nums[i]; ++j) {
                    if (nums[i + j] < 0) {
                        nums[i] = -nums[i];
                        break;
                    }
                }
            }
        }
        return nums.size() < 2 || nums.front() < 0;*/

        // 4. Greedy
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int reachable = 0;
        for (int i = 0; i < nums.size() && i <= reachable; ++i) {
            reachable = std::max(reachable, i + nums[i]);
            if (reachable >= nums.size() - 1) return true;
        }
        return false;
    }
};

/*
Tips:
*/