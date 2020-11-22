#pragma once

/* 
1528. Shuffle String
https://leetcode.com/problems/shuffle-string/

Given a string s and an integer array indices of the same length.

The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.



Example 1:


Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
Example 3:

Input: s = "aiohn", indices = [3,1,4,2,0]
Output: "nihao"
Example 4:

Input: s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
Output: "arigatou"
Example 5:

Input: s = "art", indices = [1,0,2]
Output: "rat"


Constraints:

s.length == indices.length == n
1 <= n <= 100
s contains only lower-case English letters.
0 <= indices[i] < n
All values of indices are unique (i.e. indices is a permutation of the integers from 0 to n - 1).
*/

#include <vector>
#include <string>

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        // 1. Traversal
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::string res(s);
        for (size_t i = 0; i < indices.size(); ++i) {
            res[indices[i]] = s[i];
        }
        return res;*/

        // 2. Cycle sort
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        for (size_t i = 0; i < indices.size(); ++i) {
            while (indices[i] != i) {
                std::swap(s[i], s[indices[i]]);
                std::swap(indices[i], indices[indices[i]]);
            }
        }
        return s;
    }
};

/*
Tips:
    1. Cycle sort: O(N^2) in time, O(1) in space, unstable
    2. Solution has time complexity of O(N) instead of O(N^2) since we iterate each element only once
*/