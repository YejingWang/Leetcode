#pragma once

/* 
392. Is Subsequence
https://leetcode.com/problems/is-subsequence/

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false


Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.


Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
*/

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isSub(const std::string& s, int si, const std::string& t, int ti) {
        if (si >= s.length()) return true;
        if (ti >= t.length()) return false;
        while (ti < t.length()) {
            if (s[si] == t[ti]) {
                ++si;
                break;
            }
            ++ti;
        }
        return isSub(s, si, t, ti + 1);
    }

    bool isSubsequence(std::string s, std::string t) {
        // 1. Recursion
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        //return isSub(s, 0, t, 0);

        // 2. Two pointers
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int si = 0;
        int ti = 0;
        while (si < s.length() && ti < t.length()) {
            if (t[ti] == s[si]) {
                ++si;
            }
            ++ti;
        }
        return si == s.length();

        // 3. Hashtable and binary search
        // Time complexity:     O(NlgN)
        // Space complexity:    O(N)
        /*std::unordered_map<char, std::vector<int>> m;
        for (size_t i = 0; i < t.length(); ++i) {
            m[t[i]].push_back(i);
        }

        int prev = -1;
        for (auto c : s) {
            auto cit = m.find(c);
            if (cit == m.end()) return false;
            auto pit = std::upper_bound(cit->second.begin(), cit->second.end(), prev);
            if (pit == cit->second.end()) return false;
            prev = *pit;
        }
        return true;*/
    }
};

/*
Tips:
    1. std::upper_bound has an armortized time complexity of O(lgN)
*/