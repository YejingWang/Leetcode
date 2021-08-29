#pragma once

/* 
64. Minimum Path Sum
https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



Example 1:
-------------------
|  1--|--3--|--1  |
---------------|---
|  1  |  5  |  1  |
---------------|---
|  4  |  2  |  1  |
-------------------
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 ¡ú 3 ¡ú 1 ¡ú 1 ¡ú 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        // 1. Dynamic programming
        // Time complexity:     O(MN)
        // Space complexity:    O(M)
        std::vector<int> dp(grid.size(), 0);
        for (size_t j = 0; j < grid[0].size(); ++j) {
            for (size_t i = 0; i < grid.size(); ++i) {
                if (j == 0) {
                    dp[i] = i == 0 ? grid[i][j] : dp[i - 1] + grid[i][j];
                }
                else {
                    dp[i] = i == 0 ? dp[i] + grid[i][j] : std::min(dp[i], dp[i - 1]) + grid[i][j];
                }
            }
        }
        return dp.back();
    }
};

/*
Tips:
*/