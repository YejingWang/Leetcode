#pragma once

/* 
575. Distribute Candies
https://leetcode.com/problems/distribute-candies/

Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.



Example 1:

Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
Example 2:

Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.
Example 3:

Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.


Constraints:

n == candyType.length
2 <= n <= 104
n is even.
-105 <= candyType[i] <= 105
*/

#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        // 1. Brute force
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        /*int unique = candyType.size();
        for (size_t i = 0; i < candyType.size() - 1; ++i) {
            for (size_t j = i + 1; j < candyType.size(); ++j) {
                if (candyType[i] == candyType[j]) {
                    --unique;
                    break;
                }
            }
        }
        return unique > candyType.size() / 2 ? candyType.size() / 2 : unique;*/

        // 2. Sort
        // Time complexity:     O(NlgN)
        // Space complexity:    O(1)
        /*int unique = candyType.size();
        std::sort(candyType.begin(), candyType.end());
        for (size_t i = 0; i < candyType.size() - 1; ++i) {
            if (candyType[i] == candyType[i + 1]) {
                --unique;
            }
        }
        return unique > candyType.size() / 2 ? candyType.size() / 2 : unique;*/

        // 3. Hash table
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::unordered_set<int> st;
        for (auto& type : candyType) {
            st.insert(type);
        }
        return st.size() > candyType.size() / 2 ? candyType.size() / 2 : st.size();
    }
};

/*
Tips:
*/