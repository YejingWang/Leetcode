#pragma once

/* 
633. Sum of Square Numbers
https://leetcode.com/problems/sum-of-square-numbers/

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.



Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false

Example 3:
Input: c = 4
Output: true

Example 4:
Input: c = 2
Output: true

Example 5:
Input: c = 1
Output: true


Constraints:

0 <= c <= 2^31 - 1
*/

#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        // 1. Brute force with DFS (TLE)
        // Time complexity:     O(lgC)
        // Space complexity:    O(lgC)
        /*if (c == 0) return true;
        std::unordered_set<int> s;
        s.insert(0);
        for (int i = 1; i <= c / i; ++i) {
            if (s.count(c - i * i) || c - i * i == i * i) {
                return true;
            }
            s.insert(i * i);
        }
        return false;*/

        // 2. Two pointers
        // Time complexity:     O(lgC)
        // Space complexity:    O(1)
        int a = 0;
        int b = std::sqrt(c);
        while (a <= b) {
            if (a * a == c - b * b) {
                return true;
            }
            else if (a * a > c - b * b) {
                --b;
            }
            else {
                ++a;
            }
        }
        return false;
    }
};

/*
Tips:
*/