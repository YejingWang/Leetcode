#pragma once

/* 
23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/

#include <vector>
#include <queue>

// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* r1, ListNode* r2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (r1 && r2) {
            if (r1->val < r2->val) {
                cur->next = r1;
                r1 = r1->next;
            }
            else {
                cur->next = r2;
                r2 = r2->next;
            }
            cur = cur->next;
        }
        cur->next = r1 ? r1 : r2;
        return dummy->next;
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // 1. Brute force
        // Time complexity:     O(NlgN)
        // Space complexity:    O(N)
        /*std::vector<int> v;
        for (size_t i = 0; i < lists.size(); ++i) {
            ListNode* t = lists[i];
            while (t) {
                v.push_back(t->val);
                t = t->next;
            }
        }
        std::sort(v.begin(), v.end());
        ListNode* cur = nullptr;
        for (int i = v.size() - 1; i >= 0; --i) {
            ListNode* tmp = new ListNode(v[i], cur);
            cur = tmp;
        }
        return cur;*/

        // 2. Merge one by one
        // Time complexity:     O(KN)
        // Space complexity:    O(1)
        /*ListNode* cur = nullptr;
        for (size_t i = 0; i < lists.size(); ++i) {
            cur = merge(cur, lists[i]);
        }
        return cur;*/

        // 3. Divide and conqueor/ merge sort
        // Time complexity:     O(NlgK)
        // Space complexity:    O(1)
        int sz = lists.size();
        int interval = 1;
        while (interval < sz) {
            for (size_t i = 0; i <= sz - interval; i += 2 * interval) {
                lists[i] = merge(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return sz > 0 ? lists[0] : nullptr;

        // 4. Naive usage of priority queue
        // Time complexity:     O(NlgN)
        // Space complexity:    O(N)
        /*std::priority_queue<int> q;
        for (size_t i = 0; i < lists.size(); ++i) {
            ListNode* t = lists[i];
            while (t) {
                q.push(t->val);
                t = t->next;
            }
        }
        ListNode* cur = nullptr;
        while (!q.empty()) {
            ListNode* tmp = new ListNode(q.top(), cur);
            cur = tmp;
            q.pop();
        }
        return cur;*/

        // 5. Compare all
        // Time complexity:     O(KN)
        // Space complexity:    O(1)
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (true) {
            int pos = -1;
            int min = std::numeric_limits<int>::max();
            for (size_t i = 0; i < lists.size(); ++i) {
                if (lists[i] && lists[i]->val < min) {
                    pos = i;
                    min = lists[i]->val;
                }
            }
            if (min == std::numeric_limits<int>::max()) break;
            cur->next = lists[pos];
            lists[pos] = lists[pos]->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};

/*
Tips:
*/