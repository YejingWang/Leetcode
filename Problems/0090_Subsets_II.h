#pragma once

/* 
90. Subsets II
https://leetcode.com/problems/subsets-ii/

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    void sub(std::vector<int>& nums, int start, int cnt, std::vector<int>& cur, std::vector<std::vector<int>>& res) {
        if (cnt == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            sub(nums, i + 1, cnt - 1, cur, res);
            cur.pop_back();
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        // 1. Cascading
        // Time complexity:     O(N * 2^N)
        // Space complexity:    O(N * 2^N)
        /*std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ret = { {} };
        int size = 0, startIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            startIndex = i >= 1 && nums[i] == nums[i - 1] ? size : 0;   // duplicates can only be added after newly added elements from the last step
            size = ret.size();
            for (int j = startIndex; j < size; ++j) {
                std::vector<int> tmp = ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
        }
        return ret;*/

        // 2. Backtracking with deduplication
        // Time complexity:     O(N * 2^N)
        // Space complexity:    O(N)
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        for (size_t i = 0; i <= nums.size(); ++i) {
            sub(nums, 0, i, cur, res);
        }
        return res;
    }
};

/*
Tips:
*/