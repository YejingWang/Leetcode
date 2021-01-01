#pragma once

/* 
1678. Goal Parser Interpretation
https://leetcode.com/problems/goal-parser-interpretation/

You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.



Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"
Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"


Constraints:

1 <= command.length <= 100
command consists of "G", "()", and/or "(al)" in some order.
*/

#include <string>

class Solution {
public:
    std::string interpret(std::string command) {
        // 1. Traversal
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        std::string res;
        for (size_t i = 0; i < command.length(); ++i) {
            if (command[i] == 'G') {
                res += 'G';
            }
            else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    res += 'o';
                    ++i;
                }
                else {
                    res += "al";
                    i += 3;
                }
            }
        }
        return res;
    }
};

/*
Tips:
*/