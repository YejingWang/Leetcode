#pragma once

/* 
122. Best Time to Buy and Sell Stock II
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e., max profit = 0.


Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

#include <vector>
#include <limits>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // 1. Local minima and maxima
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*int profit = 0;
        int low = prices[0];
        int high = prices[0];
        int i = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) ++i;
            low = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) ++i;
            high = prices[i];
            profit += (high - low);
        }
        return profit;*/

        // 2. One pass
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*int profit = 0;
        for (size_t i = 0; i < prices.size() - 1; ++i) {
            if (prices[i + 1] > prices[i]) {
                profit += (prices[i + 1] - prices[i]);
            }
        }
        return profit;*/

        // 3. State Machine
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int curHold = std::numeric_limits<int>::min();
        int curNotHold = 0;

        for (auto price : prices) {
            int prevHold = curHold;
            int prevNotHold = curNotHold;
            curHold = std::max(prevHold, prevNotHold - price);
            curNotHold = std::max(prevNotHold, prevHold + price);
        }
        return curNotHold;
    }
};

/*
Tips:
    1. The state machine diagram in approach 3 is like:
                                    Sell
                          -------------------------
                         |     Add stock price     |
                         \/      to balance        |
    Keep in    --->  ----------              ----------  <---   Keep in
  not holding  |    | Not hold |            |   Hold   |     |  holding
               ----  ----------              ----------  ----
                         |   Minus stock price   /\
                         |       to balance       |
                          ------------------------
                                     Buy
*/