#pragma once

/* 
997. Find the Town Judge
https://leetcode.com/problems/find-the-town-judge/

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.



Example 1:
Input: N = 2, trust = [[1,2]]
Output: 2

Example 2:
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Example 4:
Input: N = 3, trust = [[1,2],[2,3]]
Output: -1

Example 5:
Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3


Constraints:

1 <= N <= 1000
0 <= trust.length <= 10^4
trust[i].length == 2
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N
*/

#include <vector>
#include <unordered_set>

class Solution {
public:
    int findJudge(int N, std::vector<std::vector<int>>& trust) {
        // 1. unordered_set
        // Time complexity:     O(T+N)
        // Space complexity:    O(T+N)
        /*std::vector<std::unordered_set<int>> sets(N);
        std::vector<bool> trustOthers(N, false);
        for (auto& v : trust) {
            sets[v[1] - 1].insert(v[0]);
            trustOthers[v[0] - 1] = true;
        }
        for (size_t i = 0; i < sets.size(); ++i) {
            if (!trustOthers[i] && sets[i].size() == N - 1) {
                return i + 1;
            }
        }
        return -1;*/

        // 2. Better unordered_set
        // Time complexity:     O(T+N)
        // Space complexity:    O(N)
        /*std::vector<std::unordered_set<int>> sets(N);
        std::vector<bool> trustOthers(N, false);
        for (auto& v : trust) {
            if (!trustOthers[v[1] - 1]) {
                sets[v[1] - 1].insert(v[0]);
            }
            trustOthers[v[0] - 1] = true;
        }
        for (size_t i = 0; i < sets.size(); ++i) {
            if (!trustOthers[i] && sets[i].size() == N - 1) {
                return i + 1;
            }
        }
        return -1;*/

        // 3. In- and out-degrees
        // Time complexity:     O(T+N)
        // Space complexity:    O(N)
        std::vector<int> count(N, 0);
        for (auto& v : trust) {
            --count[v[0] - 1];
            ++count[v[1] - 1];
        }
        for (size_t i = 0; i < N; ++i) {
            if (count[i] == N - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};

/*
Tips:
*/