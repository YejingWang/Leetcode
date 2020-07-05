#pragma once

/* 
1. Two Sum
https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Solution 2 performs the best both in time complexity and space complexity...
        // 4 comes closely after it; 3 is moderately worse
        std::vector<int> res;

        // 1.Brute force
        // Time complexity:     O(N^2)
        // Space complexity:    o(1)
        /*for (size_t i = 0; i < nums.size() - 1; ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res*/

        // 2.Sort + 2 pointers
        // Time complexity:     O(NlogN)
        // Space complexity:    O(N)
        /*std::vector<int> tmp(nums.begin(), nums.end());
        std::sort(tmp.begin(), tmp.end());
        int pre = 0, post = nums.size() - 1;
        while (pre < post) {
            if (tmp[pre] + tmp[post] < target) {
                ++pre;
            }
            else if (tmp[pre] + tmp[post] > target) {
                --post;
            }
            else {
                break;
            }
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == tmp[pre]) {
                res.push_back(i);
            }
            else if (nums[i] == tmp[post]) {
                res.push_back(i);
            }
        }
        return res;*/

        // 3.Uses map (two-pass)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::map<int, int> mp;
        for (size_t i = 0; i < nums.size(); ++i) {
            mp[target - nums[i]] = i;
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i]) != mp.end() && mp[nums[i]] != i) {
                res.push_back(i);
                res.push_back(mp[nums[i]]);
                break;
            }
        }
        return res;*/

        // 4.Better map usage (one-pass)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); ++i) {
            if (ump.find(target - nums[i]) != ump.end()) {
                return std::vector<int>{i, ump[target - nums[i]]};
            }
            ump[nums[i]] = i;
        }
        return std::vector<int>{};
    }
};

/*
Tips:
*/