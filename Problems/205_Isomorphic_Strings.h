#pragma once

/* 
205. Isomorphic Strings
https://leetcode.com/problems/isomorphic-strings/

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true


Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        // 1. unordered_map + vector comparison
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        /*std::unordered_map<char, std::vector<int>> sm, tm;
        for (size_t i = 0; i < s.length(); ++i) {
            if (sm[s[i]] != tm[t[i]]) return false;
            sm[s[i]].push_back(i);
            tm[t[i]].push_back(i);
        }
        return true;*/

        // 2. unordered_map + index comparison
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::unordered_map<char, int> sm, tm;
        for (size_t i = 0; i < s.length(); ++i) {
            if (sm[s[i]] != tm[t[i]]) return false;
            sm[s[i]] = i + 1;
            tm[t[i]] = i + 1;
        }
        return true;*/

        // 3. unordered_map and string conversion
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::unordered_map<char, int> sm, tm;
        for (size_t i = 0; i < s.length(); ++i) {
            if (sm.find(s[i]) != sm.end()) {
                s[i] = std::to_string(sm[s[i]])[0];
            }
            else {
                sm[s[i]] = i;
                s[i] = std::to_string(i)[0];
            }
            if (tm.find(t[i]) != tm.end()) {
                t[i] = std::to_string(tm[t[i]])[0];
            }
            else {
                tm[t[i]] = i;
                t[i] = std::to_string(i)[0];
            }
        }
        return s == t;*/

        // 4. two unordered_maps
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::unordered_map<char, char> sm, tm;
        for (size_t i = 0; i < s.length(); ++i) {
            if (sm.find(s[i]) != sm.end()) {
                if (sm[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                if (tm.find(t[i]) != tm.end()) {
                    return false;
                }
                sm[s[i]] = t[i];
                tm[t[i]] = s[i];
            }
        }
        return true;*/

        // 5. unordered_map and unordered_set
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::unordered_map<char, char> sm;
        std::unordered_set<char> ts;
        for (size_t i = 0; i < s.length(); ++i) {
            if (sm.find(s[i]) != sm.end()) {
                if (sm[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                if (ts.find(t[i]) != ts.end()) {
                    return false;
                }
                sm[s[i]] = t[i];
                ts.insert(t[i]);
            }
        }
        return true;
    }
};

/*
Tips:
*/