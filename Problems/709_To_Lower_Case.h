#pragma once

/* 
709. To Lower Case
https://leetcode.com/problems/to-lower-case/

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.



Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"
*/

#include <string>

class Solution {
public:
    std::string toLowerCase(std::string str) {
        // 1.Traversal
        // Time complexity:		O(N)
        // Space complexity:	O(1)
        /*for (char& c : str) {
            if (c >= 'A' && c <= 'Z') {
                c += ('a'-'A');
            }
        }*/

        // 2.Use std::tolower()
        // Time complexity:		O(N)
        // Space complexity:	O(1)
        for (char& c : str) {
            if (c >= 'A' && c <= 'Z') {
                c = tolower(c);
            }
        }

        return str;
    }
};

/*
Tips:
*/