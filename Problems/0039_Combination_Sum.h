#pragma once

/* 
39. Combination Sum
https://leetcode.com/problems/combination-sum/

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Example 4:
Input: candidates = [1], target = 1
Output: [[1]]

Example 5:
Input: candidates = [1], target = 2
Output: [[1,1]]


Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    /*void combine(std::vector<int>& candidates, int target, size_t startIndex, std::vector<int>& cur, std::vector<std::vector<int>>& all, std::unordered_set<std::string>& st) {
        for (size_t i = startIndex; i < candidates.size(); ++i) {
            if (candidates[i] < target) {
                cur.push_back(candidates[i]);
                combine(candidates, target - candidates[i], i, cur, all, st);
                cur.pop_back();
            }
            else if (candidates[i] == target) {
                cur.push_back(candidates[i]);
                std::string hash;
                for (size_t i = 0; i < cur.size(); ++i) {
                    hash += std::to_string(cur[i]);
                }
                if (st.count(hash) == 0) {
                    all.push_back(cur);
                    st.insert(hash);
                }
                cur.pop_back();
                return;
            }
            else {
                return;
            }
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::unordered_set<std::string> st;
        std::sort(candidates.begin(), candidates.end());
        combine(candidates, target, 0, cur, res, st);
        return res;
    }*/


    void combine(std::vector<int>& candidates, int target, size_t startIndex, std::vector<int>& cur, std::vector<std::vector<int>>& all) {
        for (size_t i = startIndex; i < candidates.size(); ++i) {
            if (candidates[i] < target) {
                cur.push_back(candidates[i]);
                combine(candidates, target - candidates[i], i, cur, all);
                cur.pop_back();
            }
            else if (candidates[i] == target) {
                cur.push_back(candidates[i]);
                all.push_back(cur);
                cur.pop_back();
                return;
            }
            else {
                return;
            }
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        combine(candidates, target, 0, cur, res);
        return res;
    }
};

/*
Tips:
*/