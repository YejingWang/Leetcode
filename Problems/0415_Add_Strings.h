#pragma once

/* 
415. Add Strings
https://leetcode.com/problems/add-strings/

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.



Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"


Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/

#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        // 1. Straightforward
        // Time complexity:     O(MAX(M, N))
        // Space complexity:    O(1)
        std::string res(std::max(num1.length(), num2.length()), '0');
        int i = num1.length();
        int j = num2.length();
        int k = res.length();
        int carry = 0;
        while (i > 0 || j > 0) {
            if (i > 0) {
                carry += (num1[i - 1] - '0');
                --i;
            }
            if (j > 0) {
                carry += (num2[j - 1] - '0');
                --j;
            }
            res[k - 1] = (char)(carry % 10 + '0');
            --k;
            carry /= 10;
        }
        if (carry) {
            res = "1" + res;
        }
        return res;
    }
};

/*
Tips:
*/