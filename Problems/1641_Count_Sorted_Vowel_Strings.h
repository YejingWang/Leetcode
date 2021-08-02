#pragma once

/* 
1641. Count Sorted Vowel Strings
https://leetcode.com/problems/count-sorted-vowel-strings/

Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.



Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045


Constraints:

1 <= n <= 50
*/

#include <vector>

class Solution {
public:
    int countVowelStrings(int n) {
        // 1. Dynamic programming
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<std::vector<int>> v(n, std::vector<int>(5));
        v[0] = { 1, 2, 3, 4, 5 };

        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 0; j < 5; ++j) {
                v[i][j] = j == 0 ? 1 : v[i - 1][j - 1] + v[i - 1][j];
            }
        }
        return v.back().back();*/

        // 2. Better dynamic programming
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int vowel[5] = { 1, 2, 3, 4, 5 };
        while (n > 1) {
            for (int i = 1; i < 5; ++i) {
                vowel[i] += vowel[i - 1];
            }
            --n;
        }
        return vowel[4];

        // 3. Combination number
        // Time complexity:     O(1)
        // Space complexity:    O(1)
        //return (n + 4) * (n + 3) * (n + 2) * (n + 1) / (4 * 3 * 2 * 1);
    }
};

/*
Tips:
    1. In essence the problem is inserting 4 seperators into n vowels, thus C(n+4)(4)
*/