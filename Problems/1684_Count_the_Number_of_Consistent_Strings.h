#pragma once

/* 
1684. Count the Number of Consistent Strings
https://leetcode.com/problems/count-the-number-of-consistent-strings/

You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.



Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.


Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
*/

#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        // 1. unordered_set
        // Time complexity:     O(M * N) (M = word.length(), n = word.size())
        // Space complexity:    O(S) (S = allowed.length())
        /*int nonCon = 0;
        std::unordered_set<char> st(allowed.begin(), allowed.end());
        for (auto& word : words) {
            for (auto& c : word) {
                if (st.find(c) == st.end()) {
                    ++nonCon;
                    break;
                }
            }
        }
        return words.size() - nonCon;*/

        // 2. Boolean array
        // Time complexity:     O(M * N) (M = word.length(), n = word.size())
        // Space complexity:    O(1)
        size_t res = words.size();
        bool alpha[26] = { false };
        for (char& c : allowed) {
            alpha[c - 'a'] = true;
        }
        for (auto& word : words) {
            for (char& c : word) {
                if (!alpha[c - 'a']) {
                    --res;
                    break;
                }
            }
        }
        return res;
    }
};

/*
Tips:
    1. Array indexing is still fasting than std::unordered_set.find(), which is O(1)
*/