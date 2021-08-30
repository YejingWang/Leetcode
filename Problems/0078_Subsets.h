#pragma once

/* 
78. Subsets
https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique..
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    void sub(std::vector<int>& nums, std::vector<int>& cur, int cnt,
        int start, std::vector<std::vector<int>>& res) {
        if (cnt == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            sub(nums, cur, cnt - 1, i + 1, res);
            cur.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        // 1. Cascading
        // Time complexity:     O(N * 2^N)
        // Space complexity:    O(N * 2^N)
        /*std::vector<std::vector<int>> res;
        res.push_back(std::vector<int>());
        for (size_t i = 0; i < nums.size(); ++i) {
            std::vector<std::vector<int>> cur;
            for (auto& v : res) {
                std::vector<int> tmp(v.begin(), v.end());
                tmp.push_back(nums[i]);
                cur.push_back(tmp);
            }
            for (auto& v : cur) {
                res.push_back(v);
            }
        }
        return res;*/

        // 2. Backtracking
        // Time complexity:     O(N * 2^N)
        // Space complexity:    O(N)
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        for (size_t i = 0; i <= nums.size(); ++i) {
            sub(nums, cur, i, 0, res);
        }
        return res;
    }
};

/*
Tips:
*/