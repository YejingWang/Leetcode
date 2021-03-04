#pragma once

/* 
645. Set Mismatch
https://leetcode.com/problems/set-mismatch/

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.



Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]


Constraints:

2 <= nums.length <= 10^4
1 <= nums[i] <= 10^4
*/

#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        // 1. Sort
        // Time complexity:     O(NlgN)
        // Space complexity:    O(1)
        std::vector<int> res(2);
        std::sort(nums.begin(), nums.end());
        int sum = nums[0];
        bool bFind = false;
        for (size_t i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            if (!bFind && nums[i] == nums[i - 1]) {
                res[0] = nums[i];
                bFind = true;
            }
        }
        res[1] = res[0] - sum + nums.size() * (nums.size() + 1) / 2;
        return res;

        // 2. Hash table
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> res(2);
        int sum = 0;
        bool bFind = false;
        std::unordered_set<int> st;
        size_t prevSize = 0;
        for (auto n : nums) {
            sum += n;
            if (!bFind) {
                st.insert(n);
                if (st.size() == prevSize) {
                    res[0] = n;
                    bFind = true;
                }
                prevSize = st.size();
            }
        }
        res[1] = res[0] - sum + nums.size() * (nums.size() + 1) / 2;
        return res;*/
    }
};

/*
Tips:
*/