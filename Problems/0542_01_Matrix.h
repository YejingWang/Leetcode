#pragma once

/* 
542. 01 Matrix
https://leetcode.com/problems/01-matrix/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.



Example 1:
-------------
| 0 | 0 | 0 |
-------------
| 0 | 1 | 0 |
-------------
| 0 | 0 | 0 |
-------------
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
-------------
| 0 | 0 | 0 |
-------------
| 0 | 1 | 0 |
-------------
| 1 | 1 | 1 |
-------------
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

#include <vector>
#include <limits>
#include <algorithm>
#include <queue>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        // 1. Brute force (Time limit exceeded)
        // Time complexity:     O((MN)^2)
        // Space complexity:    O(1)
        /*std::vector<std::vector<int>> v(mat.size(),
            std::vector<int>(mat[0].size(), std::numeric_limits<int>::max()));
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 0) {
                    v[i][j] = 0;
                }
                else {
                    for (int p = 0; p < mat.size(); ++p) {
                        for (int q = 0; q < mat[0].size(); ++q) {
                            if (mat[p][q] == 0) {
                                v[i][j] = std::min(v[i][j], std::abs(p - i) + std::abs(q - j));
                            }
                        }
                    }
                }
            }
        }
        return v;*/

        // 2. In-space BFS
        // Time complexity:     O(MN)
        // Space complexity:    O(MN)
        /*std::queue<std::pair<int, int>> q;
        for (size_t i = 0; i < mat.size(); ++i) {
            for (size_t j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 0) {
                    q.push(std::make_pair(i, j));
                }
                else {
                    mat[i][j] = std::numeric_limits<int>::max();
                }
            }
        }

        int dir[4][2] = { { -1, 0}, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (size_t i = 0; i < 4; ++i) {
                int r = p.first + dir[i][0];
                int c = p.second + dir[i][1];
                if (0 <= r && 0 <= c && r < mat.size() && c < mat[0].size()) {
                    if (mat[r][c] > mat[p.first][p.second] + 1) {
                        mat[r][c] = mat[p.first][p.second] + 1;
                        q.push(std::make_pair(r, c));
                    }
                }
            }
        }
        return mat;*/

        // 3. Two-pass DP
        // Time complexity:     O(MN)
        // Space complexity:    O(1)
        std::vector<std::vector<int>> v(mat.size(),
            std::vector<int>(mat[0].size(), std::numeric_limits<short>::max()));
        for (size_t i = 0; i < v.size(); ++i) {
            for (size_t j = 0; j < v[0].size(); ++j) {
                if (mat[i][j] == 0) {
                    v[i][j] = 0;
                }
                else {
                    if (i > 0) {
                        v[i][j] = std::min(v[i - 1][j] + 1, v[i][j]);
                    }
                    if (j > 0) {
                        v[i][j] = std::min(v[i][j - 1] + 1, v[i][j]);
                    }
                }
            }
        }

        for (int i = v.size() - 1; i >= 0; --i) {
            for (int j = v[0].size() - 1; j >= 0; --j) {
                if (mat[i][j] == 0) {
                    v[i][j] = 0;
                }
                else {
                    if (i < mat.size() - 1) {
                        v[i][j] = std::min(v[i + 1][j] + 1, v[i][j]);
                    }
                    if (j < mat[0].size() - 1) {
                        v[i][j] = std::min(v[i][j + 1] + 1, v[i][j]);
                    }
                }
            }
        }

        return v;
    }
};

/*
Tips:
*/