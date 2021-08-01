#pragma once

/* 
867. Transpose Matrix
https://leetcode.com/problems/transpose-matrix/

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.





Example 1:
----------------        ----------------
|  2 |  4 | -1 |        | 2 | -10 | 18 |
----------------        ----------------
| -10 | 5 | 11 |   ==>  | 4  | 5  | -7 |
----------------        ----------------
| 18 | -7 |  6 |        | -1 | 11 |  6 |
----------------        ----------------
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-10^9 <= matrix[i][j] <= 10^9
*/

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        // 1. Straightforward
        // Time complexity:     O(MN)
        // Space complexity:    O(MN)
        std::vector<std::vector<int>> res(matrix[0].size(), std::vector<int>(matrix.size()));
        for (size_t i = 0; i < res.size(); ++i) {
            for (size_t j = 0; j < res[0].size(); ++j) {
                res[i][j] = matrix[j][i];
            }
        }
        return res;
    }
};

/*
Tips:
*/