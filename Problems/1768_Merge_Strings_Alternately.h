#pragma once

/* 
1768. Merge Strings Alternately
https://leetcode.com/problems/merge-strings-alternately/

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.



Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d


Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        // 1. Straightforward
        // Time complexity:     O(M + N)
        // Space complexity:    O(1)
        std::string res;
        for (size_t i = 0, j = 0; i < word1.length() || j < word2.length(); ++i, ++j) {
            if (i < word1.length()) {
                res.push_back(word1[i]);
            }
            if (j < word2.length()) {
                res.push_back(word2[j]);
            }
        }
        return res;
    }
};

/*
Tips:
    1.push_back and append of std::string are designed for different circumstances:
    push_back accepts a char as input, while append are used for strings and c-strings
*/