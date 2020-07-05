#pragma once

/* 
1281. Subtract the Product and Sum of Digits of an Integer
https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

Given an integer number n, return the difference between the product of its digits and the sum of its digits.


Example 1:

Input: n = 234
Output: 15
Explanation:
Product of digits = 2 * 3 * 4 = 24
Sum of digits = 2 + 3 + 4 = 9
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation:
Product of digits = 4 * 4 * 2 * 1 = 32
Sum of digits = 4 + 4 + 2 + 1 = 11
Result = 32 - 11 = 21


Constraints:

1 <= n <= 10^5
*/

#include <string>

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;

        // 1.division
        // Time complexity:     O(log(N))
        // Space complexity:    O(1)
        /*int curDigit = 0;
        while(n != 0) {
            curDigit = n % 10;
            sum += curDigit;
            product *= curDigit;
            n /= 10;
        }*/


        // 2.covert n to string
        // Time complexity:     O(log(N)) ?
        // Space complexity:    O(1)
        std::string str = std::to_string(n);
        int curDigit = 0;
        for (char c : str) {
            //curDigit = std::atoi(&c);		// throws run-time error in leetcode but compiles in vs 2017
            curDigit = c - '0';
            sum += curDigit;
            product *= curDigit;
        }

        return product - sum;
    }
};

/*
Tips:
	1.N in time complexity O(N) refers to the number of digits of the input int n
	2.for (char& c : str) {
			curDigit = std::atoi(&c);
	}s
	gives wrong answer since &c points to the entire string
*/