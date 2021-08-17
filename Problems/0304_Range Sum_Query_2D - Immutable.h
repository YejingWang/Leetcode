#pragma once

/* 
304. Range Sum Query 2D - Immutable
https://leetcode.com/problems/range-sum-query-2d-immutable/

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).


Example 1:
---------------------
| 3 | 0 | 1 | 4 | 2 |
---------------------
| 5 | 6 | 3 | 2 | 1 |
---------------------
| 1 | 2 | 0 | 1 | 5 |
---------------------
| 4 | 1 | 0 | 1 | 7 |
---------------------
| 1 | 0 | 3 | 0 | 5 |
---------------------
Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-10^5 <= matrix[i][j] <= 10^5
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 10^4 calls will be made to sumRegion.
*/

#include <vector>

class NumMatrix {
public:
    // 1. Prefix sum
    // Time complexity:
    //      construction:   O(MN)
    //      sumRange:       O(1)
    // Space complexity:    O(MN)
    NumMatrix(std::vector<std::vector<int>>& matrix) :
        mNum(matrix),
        mSums(matrix)
    {
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                if (i == 0 && j != 0) {
                    mSums[i][j] += mSums[i][j - 1];
                }
                if (j == 0 && i != 0) {
                    mSums[i][j] += mSums[i - 1][j];
                }
                if (i != 0 && j != 0) {
                    mSums[i][j] += (mSums[i][j - 1] + mSums[i - 1][j] - mSums[i - 1][j - 1]);
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) return mSums[row2][col2];
        if (row1 == 0) return mSums[row2][col2] - mSums[row2][col1 - 1];
        if (col1 == 0) return mSums[row2][col2] - mSums[row1 - 1][col2];
        return mSums[row2][col2] - mSums[row1 - 1][col2] - mSums[row2][col1 - 1] + mSums[row1 - 1][col1 - 1];
    }

    std::vector<std::vector<int>> mSums;
    std::vector<std::vector<int>> mNum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

/*
Tips:
*/