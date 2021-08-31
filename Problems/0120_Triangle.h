#pragma once

/* 
120. Triangle
https://leetcode.com/problems/triangle/

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.



Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2*
  3* 4
 6  5* 7
4  1* 8  3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10


Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-10^4 <= triangle[i][j] <= 10^4


Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    void total(std::vector<std::vector<int>>& tri, int r, int c, int sum, int& res) {
        if (r == tri.size() - 1) {
            res = std::min(res, sum);
            return;
        }
        total(tri, r + 1, c, sum + tri[r + 1][c], res);
        total(tri, r + 1, c + 1, sum + tri[r + 1][c + 1], res);
    }

    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        // 1. Iteration with stack (DFS)(TLE)
        // Time complexity:     O(N!)
        // Space complexity:    O(N)
        /*int min = std::numeric_limits<int>::max();
        std::stack<std::pair<int, std::pair<int, int>>> s;
        s.push(std::make_pair(triangle[0][0], std::make_pair(0, 0)));
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            int row = t.second.first;
            int col = t.second.second;
            if (row == triangle.size() - 1) {
                min = std::min(min, t.first);
                continue;
            }
            s.push(std::make_pair(t.first + triangle[row + 1][col], std::make_pair(row + 1, col)));
            s.push(std::make_pair(t.first + triangle[row + 1][col + 1], std::make_pair(row + 1, col + 1)));
        }
        return min;*/

        // 2. Recursion (DFS)(TLE)
        // Time complexity:     O(N!)
        // Space complexity:    O(N)
        /*int res = std::numeric_limits<int>::max();
        total(triangle, 0, 0, triangle[0][0], res);
        return res;*/

        // 3. Top-down DP
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        /*std::vector<int> dp(triangle.size());
        int res = std::numeric_limits<int>::max();
        for (size_t i = 0; i < dp.size(); ++i) {
            int tmp = 0;
            for (size_t j = 0; j <= i; ++j) {
                if (j == 0) {
                    tmp = dp[j];
                    dp[j] = dp[j] + triangle[i][j];
                }
                else if (j == i) {
                    dp[j] = tmp + triangle[i][j];
                }
                else {
                    int curTmp = dp[j];
                    dp[j] = triangle[i][j] + std::min(tmp, dp[j]);
                    tmp = curTmp;
                }
                if (i == dp.size() - 1) {
                    res = std::min(res, dp[j]);
                }
            }
        }
        return res;*/

        // 4. Slightly better top-down DP
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        /*std::vector<int> dp(triangle.size());
        int res = std::numeric_limits<int>::max();
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                }
                else if (j == i) {
                    dp[j] = dp[j - 1] + triangle[i][j];
                }
                else {
                    dp[j] = triangle[i][j] + std::min(dp[j - 1], dp[j]);
                }
                if (i == dp.size() - 1) {
                    res = std::min(res, dp[j]);
                }
            }
        }
        return res;*/

        // 5. Bottom-up DP
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        std::vector<int> dp = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (size_t j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};

/*
Tips:
*/