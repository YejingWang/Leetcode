#pragma once

/* 
46. Permutations
https://leetcode.com/problems/permutations/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]


Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <vector>
#include <unordered_set>

class Solution {
public:
    void permUnused(std::vector<std::vector<int>>& v, std::vector<int>& cur, std::unordered_set<int>& st) {
        if (st.empty()) {
            v.push_back(cur);
            return;
        }
        for (auto n : st) {
            auto tmp = st;
            tmp.erase(n);
            cur.push_back(n);
            permUnused(v, cur, tmp);
            cur.pop_back();
        }
    }

    void permUsed(std::vector<int>& nums, std::vector<std::vector<int>>& v,
            std::vector<int>& cur, std::unordered_set<int>& st) {
        if (st.size() == nums.size()) {
            v.push_back(cur);
            return;
        }
        for (auto n : nums) {
            if (!st.count(n)) {
                st.insert(n);
                cur.push_back(n);
                permUsed(nums, v, cur, st);
                cur.pop_back();
                st.erase(n);
            }
        }
    }

    void permuteSwap(std::vector<int>& nums, int begin, std::vector<std::vector<int>>& v) {
        if (begin >= nums.size() - 1) {
            v.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            std::swap(nums[begin], nums[i]);
            permuteSwap(nums, begin + 1, v);
            std::swap(nums[begin], nums[i]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        // 1. Memoize unused numbers and recurse
        // Time complexity:     O(N * N!)
        // Space complexity:    O(N)
        /*std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::unordered_set<int> st(nums.begin(), nums.end());
        perm(res, cur, st);
        return res;*/

        // 2. Memoize used numbers and recurse
        // Time complexity:     O(N!)
        // Space complexity:    O(N)
        /*std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::unordered_set<int> st;
        permUsed(nums, res, cur, st);
        return res;*/

        // 3. Swap and recurse
        // Time complexity:     O(N!)
        // Space complexity:    O(N)
        std::vector<std::vector<int>> res;
        permuteSwap(nums, 0, res);
        return res;
    }
};

/*
Tips:
*/