#pragma once

/* 
1480. Running Sum of 1d Array
https://leetcode.com/problems/running-sum-of-1d-array/

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]¡­nums[i]).

Return the running sum of nums.



Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]


Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
*/

#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        // 1.Straightforward
        // Time complexity:     O(N)
        // Space complexity:    o(1)
        std::vector<int> rSum;
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
            rSum.push_back(sum);
        }
        return rSum;
    }
};

/*
Tips:
*/