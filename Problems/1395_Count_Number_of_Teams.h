#pragma once

/* 
1395. Count Number of Teams
https://leetcode.com/problems/count-number-of-teams/

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).



Example 1:
Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).

Example 2:
Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:
Input: rating = [1,2,3,4]
Output: 4


Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 10^5
All the integers in rating are unique.
*/

#include <vector>
#include <set>

class Solution {
public:
    int numTeams(std::vector<int>& rating) {
        // 1. Brute force (TLE)
        // Time complexity:     O(N^3)
        // Space complexity:    O(1)
        /*int res = 0;
        for (size_t i = 0; i < rating.size() - 2; ++i) {
            for (size_t j = i + 1; j < rating.size() - 1; ++j) {
                for (size_t k = j + 1; k < rating.size(); ++k) {
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) ||
                        (rating[i] > rating[j] && rating[j] > rating[k])) {
                        ++res;
                    }
                }
            }
        }
        return res;*/

        // 2. Count left and right
        // Time complexity:     O(N^2)
        // Space complexity:    O(1)
        /*int res = 0;
        for (size_t i = 1; i < rating.size() - 1; ++i) {
            int left[2] = { 0, 0 };
            int right[2] = { 0, 0 };
            for (size_t j = 0; j < rating.size(); ++j) {
                if (j < i) {
                    ++left[rating[j] > rating[i]];
                }
                if (j > i) {
                    ++right[rating[j] > rating[i]];
                }
            }
            res += (left[0] * right[1] + left[1] * right[0]);
        }
        return res;*/

        // 3. std::set
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        /*int res = 0;
        std::set<int> ls, rs(rating.cbegin(), rating.cend());
        for (int i = 1; i < rating.size(); ++i) {
            ls.insert(rating[i - 1]);
            rs.erase(rating[i - 1]);

            int lsd = std::distance(ls.cbegin(), ls.lower_bound(rating[i]));
            int rld = std::distance(rs.upper_bound(rating[i]), rs.cend());
            res += lsd * rld;

            int lld = std::distance(ls.upper_bound(rating[i]), ls.cend());
            int rsd = std::distance(rs.cbegin(), rs.lower_bound(rating[i]));
            res += lld * rsd;
        }
        return res;*/
    }
};

/*
Tips:
    1. The 3rd approach takes O(N^2) time since std::set cannot be accessed randomly and thus std::distance takes linear time
    2. NlgN can be accieved using binary indexed tree
*/