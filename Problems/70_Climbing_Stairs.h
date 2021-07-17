#pragma once

/* 
70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45
*/

class Solution {
public:
    int climb(int i, int n, int stairs[]) {
        if (i > n) return 0;
        if (i == n) return 1;
        if (stairs[i] > 0) return stairs[i];
        stairs[i] = climb(i + 1, n, stairs) + climb(i + 2, n, stairs);
        return stairs[i];
    }

    int climbStairs(int n) {
        // 1. Recursion (top-down)
        // Time complexity:     O(2^N)
        // Space complexity:    O(N)
        /*if (n < 2) return 1;
        return climbStairs(n-1) + climbStairs(n-2);*/

        // 2. Recursion with memorization (top-down)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*int* stairs = new int[n+1];
        return climb(0, n, stairs);*/

        // 3. Dynamic programming (bottom-up)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (n < 2) return 1;
        int* stairs = new int[n+1];
        stairs[0] = 1;
        stairs[1] = 1;
        int i = 2;
        while (i <= n) {
            stairs[i] = stairs[i-1] + stairs[i-2];
            ++i;
        }
        return stairs[n];*/

        // 4. Fibonacci
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        if (n < 2) return 1;
        int i = 2;
        int prev = 1;
        int post = 1;
        int tmp = 0;
        while (i <= n) {
            tmp = prev + post;
            prev = post;
            post = tmp;
            ++i;
        }
        return post;

        // 5. Fibonacci formula
        // Time complexity:     O(lgN)
        // Space complexity:    O(1)
        /*double fibn = std::pow((1 + std::sqrt(5)) / 2, n+1) - std::pow((1 - std::sqrt(5)) / 2, n+1);
        return (int)(fibn / std::sqrt(5));*/
    }
};

/*
Tips:
    1. Time complexity in approach is lgN since std:::sqrt takes lgN time
*/