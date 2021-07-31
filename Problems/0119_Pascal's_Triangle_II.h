#pragma once

/* 
119. Pascal's Triangle II
https://leetcode.com/problems/pascals-triangle/

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]


Constraints:

0 <= rowIndex <= 33


Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/

#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        // 1. Store the entire Pascal's Triangle
        // Time complexity:     O(N^2)
        // Space complexity:    O(N^2)
        /*std::vector<std::vector<int>> v(rowIndex+1);
        for (size_t i = 0; i < rowIndex+1; ++i) {
            v[i].resize(i+1);
            for (size_t j = 0; j < i+1; ++j) {
                if (j == 0 || j == i) {
                    v[i][j] = 1;
                }
                else {
                    v[i][j] = v[i-1][j-1] + v[i-1][j];
                }
            }
        }
        return v.back();*/

        // 2. Generate onwards using the last position as storage
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        /*std::vector<int> v(rowIndex+1);
        for (size_t i = 0; i < v.size(); ++i) {
            for (size_t j = 0; j < i+1; ++j) {
                if (j == 0) {
                    v[j] = 1;
                    v.back() = 1;
                }
                else if (j == i) {
                    v[j] = 1;
                }
                else {
                    int tmp = v[j];
                    v[j] = v.back() + v[j];
                    v.back() = tmp;
                }
            }
        }
        return v;*/

        // 3. Generate backwards in space
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        std::vector<int> v(rowIndex + 1);
        v[0] = 1;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i; j > 0; --j) {
                v[j] += v[j - 1];
            }
        }
        return v;
    }
};

/*
Tips:
*/