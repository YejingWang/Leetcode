#pragma once

/*
1108. Defanging an IP Address
https://leetcode.com/problems/defanging-an-ip-address/

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
 

Constraints:

The given address is a valid IPv4 address.
*/

#include <string>
#include <regex>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        // 1.search from front to end
        // Time complexity:		O(N)
        // Space complexity:	O(N)
        /*for (size_t i = 0; i < address.length(); ++i){
            if (address[i] == '.'){
                address.replace(i, 1, "[.]");
                ++i;
            }
        }*/

        //  2. search from end to front to avoid index changes
        // Time complexity:		O(N)
        // Space complexity:	O(N)
        for (int i = address.length() - 1; i >= 0; --i) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
            }
        }

        return address;

        // 3. use regex_replace
        // Time complexity:     ?
        // Space complexity:    ?
        //return std::regex_replace(address, std::regex("[.]"), "[.]");
    }
};

/*
Tips:
    1.elements of a std::string are chars
    2.std::string.replace(startPos, length, newStr)
    3.TO-DO: std::regex_replace()
*/