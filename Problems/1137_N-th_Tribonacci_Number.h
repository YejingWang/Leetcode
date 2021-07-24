#pragma once

/* 
1137. N-th Tribonacci Number
https://leetcode.com/problems/n-th-tribonacci-number/

The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.



Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537


Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/

#include <vector>

class Solution {
public:
    int tribonacci(int n) {
        // 1. Recursion (Time limit exceeded)
        // Time complexity:     O(3^N)
        // Space complexity:    O(N)
        /*if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);*/

        // 2. Dynamic programming
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        std::vector<int> v(n+1);
        v[0] = 0;
        v[1] = 1;
        v[2] = 1;
        for (size_t i = 3; i <= n; ++i) {
            v[i] = v[i-3] + v[i-2] + v[i-1];
        }
        return v.back();*/

        // 3. Dynamic programming/iteration
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        /*if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        int first = 0;
        int second = 1;
        int third = 1;
        for (size_t i = 3; i <= n; ++i) {
            int tmp = first + second + third;
            first = second;
            second = third;
            third = tmp;
        }
        return third;*/

        // 4. Fancier dynamic programming/iteration
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        int dp[3] = { 0, 1, 1 };
        for (int i = 3; i <= n; ++i) {
            dp[i%3] = dp[0] + dp[1] + dp[2];
        }
        return dp[n%3];
    }
};

/*
Tips:
*/