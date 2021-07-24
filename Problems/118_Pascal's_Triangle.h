#pragma once

/* 
118. Pascal's Triangle
https://leetcode.com/problems/pascals-triangle/

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]


Constraints:

1 <= numRows <= 30
*/

#include <vector>

class Solution {
public:
    void generateNewLine(std::vector<std::vector<int>>& tri) {
        size_t sz = tri.empty() ? 1 : tri.back().size() + 1;
        std::vector<int> newV(sz);
        for (size_t i = 0; i < newV.size(); ++i) {
            if (i == 0 || i == newV.size() - 1) {
                newV[i] = 1;
            }
            else {
                newV[i] = (tri.back())[i - 1] + (tri.back())[i];
            }
        }
        tri.push_back(std::move(newV));
    }

    std::vector<std::vector<int>> generate(int numRows) {
        // 1. Top-down generation
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        std::vector<std::vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1);
            for (size_t j = 0; j < i + 1; ++j) {
                if (j == 0 || j == i) {
                    res[i][j] = 1;
                }
                else {
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
                }
            }
        }
        return res;

        // 2. Dynamic programming
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        /*std::vector<std::vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            generateNewLine(res);
        }
        return res;*/
    }
};

/*
Tips:
*/