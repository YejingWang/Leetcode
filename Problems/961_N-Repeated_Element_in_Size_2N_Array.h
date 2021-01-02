#pragma once

/*
961. N-Repeated Element in Size 2N Array
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.



Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5


Note:

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length is even
*/

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& A) {
        // 1. Comparison with unordered_map
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::unordered_map<int, int> mp;
        for (size_t i = 0; i < A.size(); ++i) {
            ++mp[A[i]];
            if (mp[A[i]] > 1) {
                return A[i];
            }
        }
        return 0;*/

        // 2. Comparison
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        bool cnt[10000]{ false };
        for (size_t i = 0; i < A.size(); ++i) {
            if (cnt[A[i]]) {
                return A[i];
            }
            cnt[A[i]] = true;
        }
        return 0;

        // 3. Sort
        // Time complexity:     O(NlogN)
        // Space complexity:    O(1)
        /*size_t half = A.size() / 2;
        std::sort(A.begin(), A.end());
        if (A[half - 1] == A[half]) {
            return A[half];
        }
        else {
            if (A[0] == A[half - 1]) {
                return A[0];
            }
            else {
                return A[half];
            }
        }
        return 0;*/

        // 4. Classification
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*for (size_t i = 2; i < A.size(); ++i) {
            if (A[i] == A[i - 1] || A[i] == A[i - 2]) {
                return A[i];
            }
        }
        return A[0];*/

        // 5. Randomization
        // Time complexity:     O(1) (Q(4) armortized; O(inf) worst case)
        // Space complexity:    O(1)
        /*int i = 0;
        int j = 0;
        size_t sz = A.size();
        while (i == j || A[i] != A[j])
            i = rand() % sz, j = rand() % sz;
        return A[i];*/
    }
};

/*
Tips:
    1. Randomization can be used for problems like this
*/