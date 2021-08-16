#pragma once

/* 
74. Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


Example 1:
---------------------
|  1 | 3  | 5  |  7 |
---------------------
| 10 | 11 | 16 | 17 |
---------------------
| 23 | 30 | 34 | 60 |
---------------------
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
---------------------
|  1 | 3  | 5  |  7 |
---------------------
| 10 | 11 | 16 | 17 |
---------------------
| 23 | 30 | 34 | 60 |
---------------------
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4
*/

#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // 1. Treat 2d matrix as an 1d one and do binary search
        // Time complexity:     O(lg(RC))
        // Space complexity:    O(1)
        int r = matrix.size();
        int c = matrix[0].size();
        int lo = 0;
        int hi = r * c;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / c][mid % c] > target) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return --lo < 0 ? false : matrix[lo / c][lo % c] == target;
    }
};

/*
Tips:
*/