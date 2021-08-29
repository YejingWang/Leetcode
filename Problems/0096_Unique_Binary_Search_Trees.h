#pragma once

/* 
96. Unique Binary Search Trees
https://leetcode.com/problems/unique-binary-search-trees/

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.



Example 1:
1      1            2            3      3
 \      \          / \          /      /
  \      \        /   \        /      /
   3      2      1     3      2      1
  /        \                 /        \
 /          \               /          \
2            3             1            2
Input: n = 3
Output: 5

Example 2:
Input: n = 1
Output: 1


Constraints:

1 <= n <= 19
*/

#include <vector>

class Solution {
public:
    int numTrees(int n) {
        // 1. Dynamic programming
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];

        // 2. Catalan number
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*long long ans = 1;
        for (long long i = 1; i <= n; ++i) {
            ans = ans * (i + n) / i;
        }
        return ans / (n + 1);*/
    }
};

/*
Tips:
    1. N-th Catalan number C(N) = (2N)! / ((N+1)! * N!)
*/