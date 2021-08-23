#pragma once

/* 
36. Valid Sudoku
https://leetcode.com/problems/valid-sudoku/

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


Example 1:
-------------------------------------
| 5 | 3 |   |   | 7 |   |   |   |   |
-------------------------------------
| 6 |   |   | 1 | 9 | 5 |   |   |   |
-------------------------------------
|   | 9 | 8 |   |   |   |   | 6 |   |
-------------------------------------
| 8 |   |   |   | 6 |   |   |   | 3 |
-------------------------------------
| 4 |   |   | 8 |   | 3 |   |   | 1 |
-------------------------------------
| 7 |   |   |   | 2 |   |   |   | 6 |
-------------------------------------
|   | 6 |   |   |   |   | 2 | 8 |   |
-------------------------------------
|   |   |   | 4 | 1 | 9 |   |   | 5 |
-------------------------------------
|   |   |   |   | 8 |   |   | 7 | 9 |
-------------------------------------
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
*/

#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // 1. Starightforward
        // Time complexity:     O(N^2)
        // Space complexity:    O(N^2)
        /*std::vector<std::vector<int>> rs(9, std::vector<int>(9, 0));
        std::vector<std::vector<int>> cs(9, std::vector<int>(9, 0));
        std::vector<std::vector<int>> ss(9, std::vector<int>(9, 0));
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    if (rs[i][c - '1'] || cs[j][c - '1'] || ss[i / 3 * 3 + j / 3][c - '1']) {
                        return false;
                    }
                    rs[i][c - '1'] = 1;
                    cs[j][c - '1'] = 1;
                    ss[i / 3 * 3 + j / 3][c - '1'] = 1;
                }
            }
        }
        return true;*/

        // 2. Bitmasking
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        std::vector<int> rs(9, 0);
        std::vector<int> cs(9, 0);
        std::vector<int> ss(9, 0);
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    int pos = 1 << (c - '1');
                    if ((rs[i] & pos) || (cs[j] & pos) || (ss[i / 3 * 3 + j / 3] & pos)) {
                        return false;
                    }
                    rs[i] |= pos;
                    cs[j] |= pos;
                    ss[i / 3 * 3 + j / 3] |= pos;
                }
            }
        }
        return true;
    }
};

/*
Tips:
*/