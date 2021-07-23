#pragma once

/* 
338. Counting Bits
https://leetcode.com/problems/counting-bits/

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101


Constraints:

0 <= n <= 105


Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
*/

#include <vector>
#include <bitset>
//#include <bit>

class Solution {
public:
    std::vector<int> countBits(int n) {
        // 1. Converting to bitwise one by one
        // Time complexity:     O(NlgN)
        // Space complexity:    O(1)
        /*std::vector<int> res(n+1);
        for (size_t i = 0; i <= n; ++i) {
            int cnt = 0;
            int tmp = i;
            while (tmp) {
                cnt += tmp % 2;
                tmp /= 2;
            }
            res[i] = cnt;
        }
        return res;*/

        // 2. popcounts
        // Time complexity:     O(NlgN)
        // Space complexity:    O(1)
        /*std::vector<int> res(n + 1);
        for (size_t i = 0; i <= n; ++i) {
            // res[i] = __builtin_popcount(i); // defined in GCC
            // res[i] = std::popcount(i);      // in C++20; including <bit> needed
            res[i] = std::bitset<32>(i).count();
        }
        return res;*/

        // 3. Dynamic programming
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        std::vector<int> res(n+1);
        for (size_t i = 0; i <= n; ++i) {
            res[i] = res[i / 2] + i % 2;
        }
        return res;

        // 4. Dynamic programming with bit manipulation
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        std::vector<int> res(n + 1);
        for (size_t i = 0; i <= n; ++i) {
            res[i] = res[i & (i-1)] + 1;
        }
        return res;

        // 5. Dynamic programming with pattern-finding
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*size_t offset = 1;
        std::vector<int> res(n + 1);
        for (size_t i = 1; i <= n; ++i) {
            if (offset * 2 == i) {
                offset *= 2;
            }
            res[i] = res[i - offset] + 1;
        }
        return res;*/
    }
};

/*
Tips:
    1. n & (n-1) clears the lowest 1 in n
*/