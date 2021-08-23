#pragma once

/* 
1979. Find Greatest Common Divisor of Array
https://leetcode.com/problems/find-greatest-common-divisor-of-array/

Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.



Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
Example 2:

Input: nums = [7,5,6,8,3]
Output: 1
Explanation:
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.
Example 3:

Input: nums = [3,3]
Output: 3
Explanation:
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.


Constraints:

2 <= nums.length <= 1000
1 <= nums[i] <= 1000
*/

#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int findGCD(std::vector<int>& nums) {
        // 1. Sort and find
        // Time complexity:     O(NlgN)
        // Space complexity:    O(1)
        /*std::sort(nums.begin(), nums.end());
        int res = nums.front();
        while (res > 0 && (nums.back() % res || nums.front() % res)) {
            --res;
        }
        return res;*/

        // 2. Implement gcd using Euclidean algorithm
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int max = std::numeric_limits<int>::min();
        int min = std::numeric_limits<int>::max();
        for (auto n : nums) {
            max = n > max ? n : max;
            min = n < min ? n : min;
        }
        return gcd(min, max);

        // 3. __gcd
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*int max = std::numeric_limits<int>::min();
        int min = std::numeric_limits<int>::max();
        for (auto n : nums) {
            max = n > max ? n : max;
            min = n < min ? n : min;
        }
        return std::__gcd(min, max);*/

        // 4. std::gcd (C++17 or later)
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*int max = std::numeric_limits<int>::min();
        int min = std::numeric_limits<int>::max();
        for (auto n : nums) {
            max = n > max ? n : max;
            min = n < min ? n : min;
        }
        return std::gcd(min, max);*/
    }
};

/*
Tips:
*/