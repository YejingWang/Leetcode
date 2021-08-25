#pragma once

/* 
22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8
*/

#include <vector>
#include <string>

class Solution {
public:
    void helper(std::vector<std::string> &res, std::string &str, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }
        if (left > 0) {
            str.push_back('(');
            helper(res, str, left - 1, right);
            str.pop_back();
        }
        if (left < right) {
            str.push_back(')');
            helper(res, str, left, right - 1);
            str.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        // 1. Recursion
        // Time complexity:     O((2n!)/((n+1)! * n!))
        // Space complexity:    O((2n!)/((n+1)! * n!))
        /*std::vector<std::string> res;
        std::string str;
        helper(res, str, n, n);
        return res;*/

        // 2. Dynamic programming
        // Time complexity:     O((2n!)/((n+1)! * n!))
        // Space complexity:    O((2n!)/((n+1)! * n!))
        std::vector<std::vector<std::string>> dp(n + 1, std::vector<std::string>());
        dp[0] = std::vector<std::string>{ "" };
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j)
                for (std::string& first : dp[j])
                    for (std::string& second : dp[i - j - 1]) {
                        std::string t = '(' + first + ')' + second;
                        dp[i].push_back(t);
                    }
        }
        return dp[n];
    }
};

/*
Tips:
    1. Time and space complexity of solutions above is the nth Catalan number
*/