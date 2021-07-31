#pragma once

/* 
746. Min Cost Climbing Stairs
https://leetcode.com/problems/min-cost-climbing-stairs/

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.



Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].


Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int minCost(const std::vector<int>& cost, int i) {
        if (i < 2) return cost[i];
        return std::min(minCost(cost, i - 2), minCost(cost, i - 1)) + cost[i];
    }

    int minCostClimbingStairs(std::vector<int>& cost) {
        // 1. Recursion
        // Time complexity:     O(2^N)
        // Space complexity:    O(N)
        //return std::min(minCost(cost, cost.size() - 1), minCost(cost, cost.size() - 2));

        // 2. Dynamic programming
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> minCosts(cost.size());
        minCosts[0] = cost[0];
        minCosts[1] = cost[1];
        for (size_t i = 2; i < minCosts.size(); ++i) {
            minCosts[i] = std::min(minCosts[i-2], minCosts[i-1]) + cost[i];
        }
        return std::min(minCosts[minCosts.size()-1], minCosts[minCosts.size()-2]);*/

        // 3. Better DP
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int prev = cost[0];
        int post = cost[1];
        int tmp = -1;
        for (size_t i = 2; i < cost.size(); ++i) {
            tmp = post;
            post = std::min(prev, post) + cost[i];
            prev = tmp;
        }
        return std::min(prev, post);
    }
};

/*
Tips:
*/