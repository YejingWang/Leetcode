#pragma once

/* 
509. Fibonacci Number
https://leetcode.com/problems/fibonacci-number/

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).



Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.


Constraints:

0 <= n <= 30
*/

#include <vector>
#include <cmath>

class Solution {
public:
    int fib(int n) {
        // 1. Recursion
        // Time complexity:     O(2^N)
        // Space complexity:    O(N)
        /*if (n < 2) return n;
        return fib(n-1) + fib(n-2);*/

        // 2. Bottom-up with memorization
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        if (n < 2) return n;
        std::vector<int> v(n + 1, 0);
        v[1] = 1;
        for (size_t i = 2; i <= n; ++i) {
            v[i] = v[i - 1] + v[i - 2];
        }
        return v.back();

        // 3. Bottom-up iteration
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*if (n < 1) return n;
        int prev = 0;
        int post = 1;
        int i = 1;
        while (i < n) {
            int tmp = post;
            post = prev + post;
            prev = tmp;
            ++i;
        }
        return post;*/

        // 4. Mathematical formula
        // Time complexity:     O(1)
        // Space complexity:    O(1)
        return std::round(std::pow((1. + std::sqrt(5.)) / 2., n) / std::sqrt(5.));
    }
};

/*
Tips:
*/