#pragma once

/* 
17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

--------------------------
|1  OO | 2  abc | 3  def |
--------------------------
|4 ghi | 5  jkl | 6  mno |
--------------------------
|7 pqrs | 8 tuv | 9 wxyz |
--------------------------

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        // 1. DFS with stack
        // Time complexity:     O(L * 4^L)
        // Space complexity:    O(L)
        /*std::vector<std::string> res;
        if (digits.size() == 0) return res;
        std::vector<std::string> v{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        std::stack<std::pair<int, std::string>> s;
        s.push(std::make_pair(0, std::string{}));
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            auto& candidate = v[digits[t.first] - '2'];
            for (auto c : candidate) {
                std::string str = t.second + c;
                if (t.first == digits.size() - 1) {
                    res.push_back(str);
                }
                else {
                    s.push(std::make_pair(t.first + 1, str));
                }
            }
        }
        return res;*/

        // 2. Iteration with swapping
        // Time complexity:     O(L * 4^L)
        // Space complexity:    O(L)
        if (digits.empty()) return std::vector<std::string>{};
        std::vector<std::string> res{ "" };
        std::vector<std::string> v{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        for (auto& c : digits) {
            std::vector<std::string> tmp;
            for (auto& s : v[c - '2']) {
                for (auto& cur : res) {
                    tmp.push_back(cur + s);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};

/*
Tips:
    1.Swapping of vectors takes constant time (no value copying)
*/