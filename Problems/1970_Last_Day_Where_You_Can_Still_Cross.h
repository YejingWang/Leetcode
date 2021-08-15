#pragma once

/* 
1970. Last Day Where You Can Still Cross
https://leetcode.com/problems/last-day-where-you-can-still-cross/

There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.



Example 1:
---------        ---------        ---------        ---------
| 0 | 0 |        | 1 | 0 |        | 1 | 0 |        | 1 | 1 |
---------  --->  ---------  --->  ---------  --->  ---------
| 0 | 0 |        | 0 | 0 |        | 1 | 0 |        | 1 | 0 |
---------        ---------        ---------        ---------
Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.

Example 2:
---------        ---------        ---------
| 0 | 0 |        | 1 | 0 |        | 1 | 1 |
---------  --->  ---------  --->  ---------
| 0 | 0 |        | 0 | 0 |        | 0 | 0 |
---------        ---------        ---------
Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.

Example 3:
-------------        -------------        -------------        -------------        -------------
| 0 | 0 | 0 |        | 0 | 1 | 0 |        | 0 | 1 | 0 |        | 0 | 1 | 0 |        | 0 | 1 | 0 |
-------------        -------------        -------------        -------------        -------------
| 0 | 0 | 0 |  --->  | 0 | 0 | 0 |  --->  | 1 | 0 | 0 |  --->  | 1 | 0 | 0 |  --->  | 1 | 1 | 0 |
-------------        -------------        -------------        -------------        -------------
| 0 | 0 | 0 |        | 0 | 0 | 0 |        | 0 | 0 | 0 |        | 0 | 0 | 1 |        | 0 | 0 | 1 |
-------------        -------------        -------------        -------------        -------------
Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.


Constraints:

2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.
*/

#include <vector>
#include <queue>
#include <stack>

class Solution {
public:
    int dirs[5] = { 0, 1, 0, -1, 0 };
    int uf[20001] = { [0 ... 20000] = -1 };

    struct Pt {
        Pt(int r, int c) :
            row(r), col(c)
        {}

        int row;
        int col;

        bool operator<(const Pt& p) const {
            return row < p.row;
        }
    };

    bool crossablePQ(int row, int col, std::vector<std::vector<int>>& cells, int day) {
        std::vector<std::vector<int>> land(row, std::vector<int>(col, 0));
        for (int i = 0; i <= day; ++i) {
            land[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        std::priority_queue<Pt> q;
        for (size_t i = 0; i < col; ++i) {
            if (land[0][i] == 0) {
                q.push(Pt(0, i));
            }
        }
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (t.row == row - 1) {
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                int r = t.row + dir[i][0];
                int c = t.col + dir[i][1];
                if (r >= 0 && r < row && c >= 0 && c < col) {
                    if (land[r][c] == 0) {
                        q.push(Pt(r, c));
                        land[r][c] = 1;
                    }
                }
            }
        }
        return false;
    }

    bool crossable(int row, int col, std::vector<std::vector<int>>& cells, int day) {
        std::vector<std::vector<int>> land(row, std::vector<int>(col, 0));
        for (int i = 0; i <= day; ++i) {
            land[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        std::stack<std::pair<int, int>> s;
        for (size_t i = 0; i < col; ++i) {
            if (land[0][i] == 0) {
                s.push(std::make_pair(0, i));
            }
        }
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (t.first == row - 1) {
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                int r = t.first + dir[i][0];
                int c = t.second + dir[i][1];
                if (r >= 0 && r < row && c >= 0 && c < col) {
                    if (land[r][c] == 0) {
                        s.push(std::make_pair(r, c));
                        land[r][c] = 1;
                    }
                }
            }
        }
        return false;
    }

    int find(int i) {
        return uf[i] < 0 ? i : uf[i] = find(uf[i]);
    }

    int latestDayToCross(int row, int col, std::vector<std::vector<int>>& cells) {
        // 1. Binary search + DFS
        // Time complexity:     O(RClgD)
        // Space complexity:    O(RC)
        /*int lo = 0;
        int hi = cells.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (crossable(row, col, cells, mid)) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo;*/

        // 2. Binary search + priority queue
        // Time complexity:     O(RClgD)
        // Space complexity:    O(RC)
        /*int lo = 0;
        int hi = cells.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (crossablePQ(row, col, cells, mid)) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo;*/

        // 3. Union find
        // Time complexity:     O(RC)
        // Space complexity:    O(RC)
        std::vector<std::vector<int>> land(row, std::vector<int>(col, 1));

        auto joinSurrounding = [&](int i, int j) {
            int p1 = find(i * col + j);
            for (int d = 0; d < 4; ++d) {
                int x = i + dirs[d];
                int y = j + dirs[d + 1];
                if (x < 0 || x >= row || y < 0 || y >= col || land[x][y] == 1) {
                    continue;
                }
                int p2 = find(x * col + y);
                if (p1 != p2) {
                    uf[std::max(p1, p2)] = std::min(p1, p2);
                    p1 = std::min(p1, p2);
                }
            }
            return p1;
        };

        for (int i = cells.size() - 1; i >= 0; --i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            land[r][c] = 0;
            if (joinSurrounding(r, c) < col) {
                for (size_t j = 0; j < col; ++j) {
                    if (find((row - 1) * col + j) < col) {  // if any of the bottom cells is connected to a top cell 
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};

/*
Tips:
*/