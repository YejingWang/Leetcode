#pragma once

/* 
1981. Minimize the Difference Between Target and Chosen Elements
https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/

You are given an m x n integer matrix mat and an integer target.

Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.

Return the minimum absolute difference.

The absolute difference between two numbers a and b is the absolute value of a - b.



Example 1:
-------------
| 1 | 2 | 3 |
-------------
| 4 | 5 | 6 |
-------------
| 7 | 8 | 9 |
-------------
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
Output: 0
Explanation: One possible choice is to:
- Choose 1 from the first row.
- Choose 5 from the second row.
- Choose 7 from the third row.
The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.

Example 2:
-----
| 1 |
-----
| 2 |
-------
| 3 |
-----
Input: mat = [[1],[2],[3]], target = 100
Output: 94
Explanation: The best possible choice is to:
- Choose 1 from the first row.
- Choose 2 from the second row.
- Choose 3 from the third row.
The sum of the chosen elements is 6, and the absolute difference is 94.

Example 3:
---------------------
| 1 | 2 | 9 | 8 | 7 |
---------------------
Input: mat = [[1,2,9,8,7]], target = 6
Output: 1
Explanation: The best choice is to choose 7 from the first row.
The absolute difference is 1.


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 70
1 <= mat[i][j] <= 70
1 <= target <= 800
*/

#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int dfs(int i, int sum, int target, std::vector<std::set<int>>& m, std::vector<std::vector<int>>& dp) {
        if (i >= m.size()) return std::abs(sum - target);
        if (dp[i][sum] == std::numeric_limits<int>::max()) {
            for (auto it = m[i].begin(); it != m[i].end(); ++it) {
                dp[i][sum] = std::min(dp[i][sum], dfs(i + 1, sum + *it, target, m, dp));
                if (dp[i][sum] == 0 || sum + *it > target)
                    break;
            }
        }
        return dp[i][sum];
    }

    int minimizeTheDifference(std::vector<std::vector<int>>& mat, int target) {
        // 1. Brute force with DFS (TLE)
        // Time complexity:     O(N^M)
        // Space complexity:    O(1)
        /*int res = std::numeric_limits<int>::max();
        int height = mat.size();
        int width = mat[0].size();
        std::stack<std::pair<int, int>> s;
        for (size_t i = 0; i < width; ++i) {
            s.push(std::make_pair(i, 0));
        }
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            int sum = t.second + mat[t.first / width][t.first % width];
            if (t.first / width == height - 1) {
                int diff = std::abs(sum - target);
                res = diff < res ? diff : res;
            }
            else {
                for (size_t i = 0; i < width; ++i) {
                    int index = (t.first / width + 1) * width + i;
                    s.push(std::make_pair(index, sum));
                }
            }
        }
        return res;*/

        // 2. Recursion
        // Time complexity:     O(N^M)
        // Space complexity:    O(1)
        /*std::vector<std::set<int>> m;
        for (auto& row : mat) {
            m.push_back(std::set<int>(row.begin(), row.end()));
        }
        std::vector<std::vector<int>> dp(71, std::vector<int>(4901, std::numeric_limits<int>::max()));
        return dfs(0, 0, target, m, dp);*/

        // 3. Use bit array for memoization
        // Time complexity:     O(MN)
        // Space complexity:    O(1)
        bool bt[70 * 70 + 1] = {};
        int max_e = 0, res = std::numeric_limits<int>::max();
        for (auto& row : mat) {
            bool bt1[70 * 70 + 1] = {};
            int max_e1 = 0;
            for (auto i : std::unordered_set<int>(row.begin(), row.end())) {
                for (int j = 0; j <= max_e; ++j) {
                    if (j == max_e || bt[j]) {
                        bt1[i + j] = true;
                        max_e1 = std::max(max_e1, i + j);
                    }
                }
            }
            std::swap(bt, bt1);
            max_e = max_e1;
        }
        for (int i = 0; i <= 70 * 70; ++i) {
            if (bt[i])
                res = std::min(res, std::abs(i - target));
        }
        return res;
    }
};

/*
Tips:
    2. The space complexity of solution 2 and 3 is O(1) since the upper bound of the problem is given
*/