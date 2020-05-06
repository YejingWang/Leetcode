#pragma once

/* 
1351. Count Negative Numbers in a Sorted Matrix
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise.

Return the number of negative numbers in grid.



Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3
Example 4:

Input: grid = [[-1]]
Output: 1


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
*/

#include <vector>

class Solution {
public:
	int countNegatives(std::vector<std::vector<int>>& grid) {
		// 1. Brute force traversal
		// Time complexity:		O(N*M)
		// Space complexity:	O(1)
		/*int cnt = 0;
		for (size_t i = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] < 0) {
					++cnt;
				}
			}
		}
		return cnt;*/

		// 2. Better brute force traversal
		// Time complexity:		O(N*M)
		// Space complexity:	O(1)
		/*int cnt = 0;
		for (size_t i = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] < 0) {
					cnt +=  grid[0].size() - j;
					break;
				}
			}
		}
		return cnt;*/

		// 3. Betterer brute force traversal
		// Time complexity:		O(lgN*M)
		// Space complexity:	O(1)
		/*int cnt = 0, posRow = grid.size(), posCol = grid[0].size();
		for (size_t i = 0; i < posRow; ++i) {
			for (size_t j = 0; j < posCol; ++j) {
				if (grid[i][j] < 0) {
					cnt += (posRow - i) * (posCol - j);
					posCol = j;
					break;
				}
			}
		}
		return cnt;*/

		// 4. Binary search
		// Time complexity:		O(N*M)
		// Space complexity:	O(1)

		// 5.Traverse from upper-right to lower-left
		// Time complexity:		O(N+M)
		// Space complexity:	O(1)
		int cnt = 0;
		int colNo = grid[0].size() - 1;
		int posCol = colNo;
		for (size_t i = 0; i < grid.size(); ++i) {
			for (int j = posCol; j >= 0; --j) {
				if (grid[i][j] >= 0) {
					cnt += (colNo - j);
					posCol = j;
					break;
				}
				else if (j == 0) {
					cnt += (colNo + 1);
				}
			}
		}
		return cnt;
	}
};

/*
Tips:
*/