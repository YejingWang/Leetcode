#pragma once

/* 
9. Palindrome Number
https://leetcode.com/problems/palindrome-number/

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.



Example 1:
Input: x = 121
Output: true

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Example 4:
Input: x = -101
Output: false


Constraints:

-2^31 <= x <= 2^31 - 1


Follow up: Could you solve it without converting the integer to a string?
*/

#include <string>
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        // 1. std::to_string
        // Time complexity:     O(lgN)
        // Space complexity:    O(lgN)
        /*if (x < 0) return false;
        std::string s = std::to_string(x);
        for (int i = 0; i < s.length() - i; ++i) {
            if (s[i] != s[s.length() - i - 1]) {
                return false;
            }
        }
        return true;*/

        // 2. Use vector to store
        // Time complexity:     O(lgN)
        // Space complexity:    O(lgN)
        /*if (x < 0) return false;
        std::vector<int> v;
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0; i < v.size() - i; ++i) {
            if (v[i] != v[v.size() - i - 1]) {
                return false;
            }
        }
        return true;*/

        // 3. Revert half of the number
        // Time complexity:     O(lgN)
        // Space complexity:    O(1)
        if (x < 0) return false;
        if (x % 10 == 0 && x != 0) return false;
        int half = 0;
        while (x > half) {
            half = half * 10 + x % 10;
            x /= 10;
        }
        return x == half || x == half / 10;
    }
};

/*
Tips:
*/