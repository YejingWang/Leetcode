#pragma once

/* 
63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.



Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1


Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        // 1. 2d dp
        // Time complexity:     O(M*N)
        // Space complexity:    O(M*N)
        /*std::vector<std::vector<int>> paths(obstacleGrid.size(), std::vector<int>(obstacleGrid[0].size(), 0));
        for (size_t i = 0; i < obstacleGrid.size(); ++i) {
            for (size_t j = 0; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] == 0) {
                    if (i == 0) {
                        if (j == 0) {
                            paths[i][j] = 1;
                        }
                        else {
                            paths[i][j] = paths[i][j-1];
                        }
                    }
                    else {
                        if (j == 0) {
                            paths[i][j] = paths[i-1][j];
                        }
                        else {
                            paths[i][j] = paths[i-1][j] + paths[i][j-1];
                        }
                    }
                }
            }
        }
        return paths.back().back();*/

        // 2. 1d dp
        // Time complexity:     O(M*N)
        // Space complexity:    O(M)
        /*std::vector<int> paths(obstacleGrid.size(), 1);
        for (size_t j = 0; j < obstacleGrid[0].size(); ++j) {
            for (size_t i = 0; i < obstacleGrid.size(); ++i) {
                if (obstacleGrid[i][j]) {
                    paths[i] = 0;
                }
                else if (i != 0) {
                    if (j == 0) {
                        paths[i] = paths[i-1];
                    }
                    else {
                        paths[i] += paths[i-1];
                    }
                }
            }
        }
        return paths.back();*/

        // 3. 2d dp using the input as storage
        // Time complexity:     O(M*N)
        // Space complexity:    O(1)
        for (size_t i = 0; i < obstacleGrid.size(); ++i) {
            for (size_t j = 0; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] == 0) {
                    if (i == 0) {
                        if (j == 0) {
                            obstacleGrid[i][j] = 1;
                        }
                        else {
                            obstacleGrid[i][j] = obstacleGrid[i][j - 1];
                        }
                    }
                    else {
                        if (j == 0) {
                            obstacleGrid[i][j] = obstacleGrid[i - 1][j];
                        }
                        else {
                            obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                        }
                    }
                }
                else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid.back().back();
    }
};

/*
Tips:
*/