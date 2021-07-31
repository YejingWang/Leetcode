#pragma once

/* 
62. Unique Paths
https://leetcode.com/problems/two-sum/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6


Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 1. 2d dp
        // Time complexity:     O(M*N)
        // Space complexity:    O(M*N)
        /*std::vector<std::vector<int>> paths(m, std::vector<int>(n, 0));
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    paths[i][j] = 1;
                }
                else {
                     paths[i][j] = paths[i-1][j] + paths[i][j-1];
                }
            }
        }
        return paths[m-1][n-1];*/

        // 2. Better 2d dp
        // Time complexity:     O(M*N)
        // Space complexity:    O(M*N)
        /*std::vector<std::vector<int>> paths(m, std::vector<int>(n, 1));
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[m-1][n-1];*/

        // 3. 1d dp
        // Time complexity:     O(M*N)
        // Space complexity:    O(M)
        /*std::vector<int> cur(m, 1);
        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 1; j < m; ++j) {
                cur[j] += cur[j-1];
            }
        }
        return cur[m-1];*/

        // 4. Mathmetical approach
        // Time complexity:     O(M)
        // Space complexity:    O(1)
        if (m > n) std::swap(m, n);
        long int res = 1;
        for (int i = n, j = 1; j < m; ++i, ++j) {
            res *= i;
            res /= j;
        }
        return (int)res;
    }
};

/*
Tips:
    1. We are actually taking m-1 steps out of the total m+n-2 steps need from the top left corner to the bottom right corner
    2. In approach 4 we need to start the loop from j = 1 since looping backwards causes inaccurate int division
    3. In approach 4 res is declared as long int to avoid overflow
*/