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
        // 1. Brute force
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        std::vector<int> res(2);
        int dup = 0;
        int missing = 0;
        for (size_t i = 1; i < nums.size() + 1; ++i) {
            int count = 0;
            for (auto n : nums) {
                if (n == i) {
                    ++count;
                }
            }
            if (count == 2) {
                dup = i;
            }
            else if (count == 0) {
                missing = i;
            }
            if (dup * missing > 0) {
                break;
            }
        }
        return std::vector<int>{ dup, missing };

        // 2. Sort
        // Time complexity:     O(NlgN)
        // Space complexity:    O(1)
        std::vector<int> res(2);
        std::sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                res[0] = nums[i - 1];
            }
            else if (nums[i] > nums[i - 1] + 1) {
                res[1] = nums[i - 1] + 1;
            }
        }
        if (nums.front() != 1) {
            res[1] = 1;
        }
        if (nums.back() != nums.size()) {
            res[1] = nums.size();
        }
        return res;

        // 3. Hash table
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::vector<int> res(2);
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
        return res;

        // 4. Inversion
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        std::vector<int> res(2);
        for (auto n : nums) {
            if (nums[std::abs(n) - 1] < 0) {
                res[0] = std::abs(n);
            }
            else {
                nums[std::abs(n) - 1] *= -1;
            }
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res[1] = i + 1;
            }
        }
        return res;
    }
};

/*
Tips:
    1. Inversion can be used to find an element that occurs twice
*/