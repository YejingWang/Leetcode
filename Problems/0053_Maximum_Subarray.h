#pragma once

/* 
53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.



Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23


Constraints:

1 <= nums.length <= 3 * 10^4
-105 <= nums[i] <= 105


Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <vector>
#include <limits>
#include <algorithm>

class Solution {
public:
    int maxSub(std::vector<int>& v, int l, int r) {
        if (l > r) return std::numeric_limits<int>::min();
        int m = l + (r - l) / 2;
        int ml = 0;
        int mr = 0;
        int lMax = maxSub(v, l, m - 1);
        int rMax = maxSub(v, m + 1, r);
        for (int i = m - 1, sum = 0; i >= l; --i) {
            sum += v[i];
            ml = std::max(ml, sum);
        }
        for (int i = m + 1, sum = 0; i <= r; ++i) {
            sum += v[i];
            mr = std::max(mr, sum);
        }
        return std::max(ml + mr + v[m], std::max(lMax, rMax));
    }

    int maxSubArray(std::vector<int>& nums) {
        // 1. Brute force
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        /*int res = std::numeric_limits<int>::min();
        for (size_t i = 0; i < nums.size(); ++i) {
            int sum = 0;
            int max = std::numeric_limits<int>::min();
            for (size_t j = i; j < nums.size(); ++j) {
                sum += nums[j];
                max = sum > max ? sum : max;
            }
            res = max > res ? max : sum;
        }
        return res;*/

        // 2. Dynamic programming
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> v(nums.size());
        v[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            v[i] = v[i - 1] > 0 ? v[i - 1] + nums[i] : nums[i];
        }
        return *std::max_element(v.begin(), v.end());*/

        // 3. Better DP
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int max = nums[0];
        int sum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            sum = sum > 0 ? sum + nums[i] : nums[i];
            max = sum > max ? sum : max;
        }
        return max;

        // 4. Divide and conquer
        // Time complexity:     O(NlgN)
        // Space complexity:    O(lgN)
        //return maxSub(nums, 0, nums.size() - 1);
    }
};

/*
Tips:
*/