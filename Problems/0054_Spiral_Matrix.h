#pragma once

/* 
54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/

Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:
-------------
| 1-|-2-|-3 |
----------|--
| 4-|-5 | 6 |
--|-------|--
| 9-|-8-|-7 |
-------------
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
--------------------
| 1--|-2-|-3--|--4 |
-----------------|--
| 5--|-6-|--7 |  8 |
--|--------------|--
| 9-|-10-|-11-|-12 |
--------------------
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        // 1. By definition
        // Time complexity:     O(RC)
        // Space complexity:    O(1)
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = -1, k = 0, up = 0, left = 0, bottom = row - 1, right = col - 1;
        int dir[4] = { 0, 1, 0, -1 };
        std::vector<int> res(row * col);
        int cnt = 0;
        while (up <= bottom && left <= right) {
            int newI = i + dir[k % 4];
            int newJ = j + dir[(k + 1) % 4];
            ++k;
            if (newI < up) {
                ++left;
            }
            else if (newI > bottom) {
                --right;
            }
            else if (newJ < left) {
                --bottom;
            }
            else if (newJ > right) {
                ++up;
            }
            else {
                --k;
                i = newI;
                j = newJ;
                res[cnt++] = matrix[i][j];
            }
        }
        return res;
    }
};

/*
Tips:
*/