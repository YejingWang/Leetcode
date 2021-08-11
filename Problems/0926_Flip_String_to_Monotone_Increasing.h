#pragma once

/* 
926. Flip String to Monotone Increasing
https://leetcode.com/problems/flip-string-to-monotone-increasing/

A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.



Example 1:
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Example 2:
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

Example 3:
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.


Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
*/

#include <string>
#include <algorithm>

class Solution {
public:
    int minFlipsMonoIncr(std::string s) {
        // 1. Dynamic programming
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int ones = 0;
        int flips = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                flips = std::min(ones, flips + 1);
            }
            else {
                ++ones;
            }
        }
        return flips;
    }
};

/*
Tips:
*/