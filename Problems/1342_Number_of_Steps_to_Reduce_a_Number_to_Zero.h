#pragma once

/* 
1342. Number of Steps to Reduce a Number to Zero
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

Given a non-negative integer num, return the number of steps to reduce it to zero. If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.



Example 1:

Input: num = 14
Output: 6
Explanation:
Step 1) 14 is even; divide by 2 and obtain 7.
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3.
Step 4) 3 is odd; subtract 1 and obtain 2.
Step 5) 2 is even; divide by 2 and obtain 1.
Step 6) 1 is odd; subtract 1 and obtain 0.
Example 2:

Input: num = 8
Output: 4
Explanation:
Step 1) 8 is even; divide by 2 and obtain 4.
Step 2) 4 is even; divide by 2 and obtain 2.
Step 3) 2 is even; divide by 2 and obtain 1.
Step 4) 1 is odd; subtract 1 and obtain 0.
Example 3:

Input: num = 123
Output: 12


Constraints:

0 <= num <= 10^6
*/

#include <vector>
#include <bitset>

class Solution {
public:
    int numberOfSteps(int num) {
        // 1.Division
        // Time complexity:     O(logN)
        // Space complexity:    O(1)
        /*int res = 0;
        while (num > 0) {
            if (num % 2) {
                --num;
            }
            else{
                num /= 2;
            }
            ++res;
        }
        return res;*/

        // 2.Bit manipulation
        // Time complexity:     O(logN)
        // Space complexity:    O(1)
        return num ? log2(num) + std::bitset<32>(num).count() : 0;

        // 3.Builtin functions in GCC compiler
        // Time complexity:     O(logN)
        // Space complexity:    O(1)
        //return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
	}
};

/*
Tips:
    1.std::bitset stores bits; can be constructed from a int; count() returns the number of bits that are set(that have a value of 1)
    2.__builtin_popcount() and __builtin_clz() are builtint functions in GCC compiler that count the number of one¡¯s(set bits) in
    an integer and  count the leading zeros of the integer respectively
*/