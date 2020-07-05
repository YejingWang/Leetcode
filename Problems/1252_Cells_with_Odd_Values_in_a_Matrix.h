#pragma once

/* 
1252. Cells with Odd Values in a Matrix
https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.

Return the number of cells with odd values in the matrix after applying the increment to all indices.



Example 1:


Input: n = 2, m = 3, indices = [[0,1],[1,1]]
Output: 6
Explanation: Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.
Example 2:


Input: n = 2, m = 2, indices = [[1,1],[0,0]]
Output: 0
Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the final matrix.


Constraints:

1 <= n <= 50
1 <= m <= 50
1 <= indices.length <= 100
0 <= indices[i][0] < n
0 <= indices[i][1] < m
*/

#include <vector>

class Solution {
public:
    int oddCells(int n, int m, std::vector<std::vector<int>>& indices) {
        // 1. Brute force traversal
        // Time complexity:		O(I*(N+M) + N*M)
        // Space complexity:	O(N*M)
        /*int res = 0;
        std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 0));
        for (size_t i = 0; i < indices.size(); ++i) {
            for (size_t j = 0; j < m; ++j) {
                ++matrix[indices[i][0]][j];
			}
            for (size_t j = 0; j < n; ++j) {
                ++matrix[j][indices[i][1]];
            }
        }
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (matrix[i][j] % 2 != 0) {
                    ++res;
                }
            }
        }

        return res;*/

        // 2.Logic deduction + brute force
        // Time complexity:	O(I+N+M)
        // Space complexity:	O(N*M)
        /*std::vector<bool> row(n, false);
        std::vector<bool> col(m, false);
        for (size_t i = 0; i < indices.size(); ++i) {
            row[indices[i][0]] = !row[indices[i][0]];
            col[indices[i][1]] = !col[indices[i][1]];
        }

        int res = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (row[i] ^ col[j]) {
                    ++res;
                }
            }
        }
        return res;*/

        // 3.Logic deduction
        // Time complexity:		O(I+N+M)
        // Space complexity:	O(N+M)
        std::vector<bool> row(n, false);
        std::vector<bool> col(m, false);
        for (size_t i = 0; i < indices.size(); ++i) {
            row[indices[i][0]] = !row[indices[i][0]];
            col[indices[i][1]] = !col[indices[i][1]];
        }

        int rCnt = 0;
        for (size_t i = 0; i < n; ++i) {
            rCnt += row[i];
        }

        int cCnt = 0;
        for (size_t i = 0; i < m; ++i) {
            cCnt += col[i];
        }

        return rCnt * m + cCnt * n - 2 * rCnt * cCnt;
    }
};

/*
Tips:
*/