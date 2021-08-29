#pragma once

/* 
5855. Find the Kth Largest Integer in the Array
https://leetcode.com/contest/weekly-contest-256/problems/find-the-kth-largest-integer-in-the-array/

You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

Return the string that represents the kth largest integer in nums.

Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.



Example 1:
Input: nums = ["3","6","7","10"], k = 4
Output: "3"
Explanation:
The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
The 4th largest integer in nums is "3".

Example 2:
Input: nums = ["2","21","12","1"], k = 3
Output: "2"
Explanation:
The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
The 3rd largest integer in nums is "2".

Example 3:
Input: nums = ["0","0"], k = 2
Output: "0"
Explanation:
The numbers in nums sorted in non-decreasing order are ["0","0"].
The 2nd largest integer in nums is "0".


Constraints:

1 <= k <= nums.length <= 10^4
1 <= nums[i].length <= 100
nums[i] consists of only digits.
nums[i] will not have any leading zeros.
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    static bool comp(std::string& s1, std::string& s2) {
        if (s1.size() != s2.size()) return s1.size() < s2.size();
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] < s2[i]) {
                return true;
            }
            else if (s1[i] > s2[i]) {
                return false;
            }
        }
        return false;
    }

    static bool compS(std::string& s1, std::string& s2) {
        if (s1.size() != s2.size()) {
            return s1.size() < s2.size();
        }
        else {
            return s1 < s2;
        }
    }

    static bool compL(std::string& s1, std::string& s2) {
        if (s1.size() != s2.size()) {
            return s1.size() > s2.size();
        }
        else {
            return s1 > s2;
        }
    }

    std::string kthLargestNumber(std::vector<std::string>& nums, int k) {
        // 1. Comparator overriding (manually comparing strings) and sorting
        // Time complexity:     O(NLlogN)
        // Space complexity:    O(1)
        /*std::sort(nums.begin(), nums.end(), compManual);
        return nums[nums.size() - k];*/

        // 2. Comparator overriding and sorting
        // Time complexity:     O(NLlogN)
        // Space complexity:    O(1)
        /*std::sort(nums.begin(), nums.end(), compS);
        return nums[nums.size() - k];*/

        // 3. Comparator overriding and sorting
        // Time complexity:     O(NL)
        // Space complexity:    O(1)
        std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), compL);
        return nums[k - 1];
    }
};

/*
Tips:
    1. In std::sort, the customized comparator requires that if comp(a, b) == true, comp(b, a) == false
    2. std::nth_element set nth element in its place as is in a sorted sequence
*/