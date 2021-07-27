#pragma once

/* 
16. 3Sum Closest
https://leetcode.com/problems/3sum-closest/

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // 1. Brute force
        // Time complexity:     O(N^3)
        // Space complexity:    O(1)
        /*int closest = std::numeric_limits<int>::max();
        int minDiff = std::numeric_limits<int>::max();
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            for (size_t j = i + 1; j < nums.size() - 1; ++j) {
                for (size_t k = j + 1; k < nums.size(); ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (std::abs(sum - target) < minDiff) {
                        minDiff = std::abs(sum - target);
                        closest = sum;
                    }
                }
            }
        }
        return closest;*/

        // 2. Two pointers
        // Time complexity:     O(N^2)
        // Space complexity:    O(1) ~ O(lgN) ~ O(N) depending on the sorting algorithm
        std::sort(nums.begin(), nums.end());
        int closest = std::numeric_limits<int>::max();
        int minDiff = std::numeric_limits<int>::max();
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            size_t j = i + 1;
            size_t k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (std::abs(sum - target) < minDiff) {
                    minDiff = std::abs(sum - target);
                    closest = sum;
                }
                if (sum > target) {
                    --k;
                }
                else if (sum < target) {
                    ++j;
                }
                else {
                    return target;
                }
            }
        }
        return closest;

        // 3. Binary search
        // Time complexity:     O(N^2 * lgN)
        // Space complexity:    O(1) ~ O(lgN) ~ O(N) depending on the sorting algorithm
        /*std::sort(nums.begin(), nums.end());
        int diff = std::numeric_limits<int>::max();
        for (size_t i = 0; i < nums.size() - 2 && diff != 0; ++i) {
            for (size_t j = i + 1; j < nums.size() - 1; ++j) {
                int complement = target - nums[i] - nums[j];
                auto it = std::upper_bound(nums.begin() + j + 1, nums.end(), complement);
                int hi = it - nums.begin();
                int lo = hi - 1;
                if (hi < nums.size() && std::abs(complement - nums[hi]) < std::abs(diff)) {
                    diff = complement - nums[hi];
                }
                if (lo > j && std::abs(complement - nums[lo]) < std::abs(diff)) {
                    diff = complement - nums[lo];
                }
            }

        }
        return target - diff;*/
    }
};

/*
Tips:
*/