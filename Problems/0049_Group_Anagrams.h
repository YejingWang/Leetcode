#pragma once

/* 
49. Group Anagrams
https://leetcode.com/problems/group-anagrams/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // 1. Build key using letters
        // Time complexity:     O(N * L)
        // Space complexity:    O(N * L)
        /*std::vector<std::vector<std::string>> v;
        std::unordered_map<std::string, std::vector<std::string>> m;
        for (auto& str : strs) {
            int letters[26] = {0};
            for (auto c : str) {
                ++letters[c - 'a'];
            }
            std::string key;
            for (size_t i = 0; i < 26; ++i) {
                key.insert(key.end(), letters[i], i + 'a');
            }
            m[key].push_back(str);
        }
        v.reserve(m.size());
        for (auto& e : m) {
            v.push_back(e.second);
        }
        return v;*/

        // 2. Build key using numbers and letters
        // Time complexity:     O(N * L)
        // Space complexity:    O(N * L)
        /*std::vector<std::vector<std::string>> v;
        std::unordered_map<std::string, std::vector<std::string>> m;
        for (auto& str : strs) {
            int letters[26] = { 0 };
            for (auto c : str) {
                ++letters[c - 'a'];
            }
            std::string key;
            for (size_t i = 0; i < 26; ++i) {
                if (letters[i]) {
                    key += std::to_string(letters[i]);
                    key += (i + 'a');
                }
            }
            m[key].push_back(str);
        }
        v.reserve(m.size());
        for (auto& e : m) {
            v.push_back(e.second);
        }
        return v;*/

        // 3. Build key using letters
        // Time complexity:     O(N * L * lgL)
        // Space complexity:    O(N * L)
        std::vector<std::vector<std::string>> v;
        std::unordered_map<std::string, std::vector<std::string>> m;
        for (auto& str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());
            m[key].push_back(str);
        }
        v.reserve(m.size());
        for (auto& e : m) {
            v.push_back(e.second);
        }
        return v;

        // 4. Build key using prime numbers
        // Time complexity:     O(N * L)
        // Space complexity:    O(N * L)
        /*int primes[26] = { 2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };

        std::vector<std::vector<std::string>> v;
        std::unordered_map<unsigned long long, std::vector<std::string>> m;
        for (auto& str : strs) {
            unsigned long long key = 1;
            for (auto c : str) {
                key *= primes[c - 'a'];
            }
            m[key].push_back(str);
        }
        v.reserve(m.size());
        for (auto& e : m) {
            v.push_back(e.second);
        }
        return v;*/
    }
};

/*
Tips:
    1. The key to this problem is to find a way to represent anagrams ("hashing")
*/