#pragma once

/* 
24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.



Example 1:

1 -----> 2 -----> 3 -----> 4
            ||
            ||
            \/
2 -----> 1 -----> 4 -----> 3

Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]


Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100


Follow up: Can you solve the problem without modifying the values in the list's nodes? (i.e., Only nodes themselves may be changed.)
*/

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
    ListNode* swapPairs(ListNode* head) {
        // 1. Swap values
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode* ret = head;
        while (head && head->next) {
            std::swap(head->val, head->next->val);
            head = head->next->next;
        }
        return ret;*/

        // 2. Swap nodes
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        ListNode* prevHead = nullptr;
        ListNode* tmp = nullptr;
        ListNode* ret = head ? (head->next ? head->next : head) : nullptr;

        while (head && head->next) {
            tmp = head->next;
            head->next = head->next->next;
            tmp->next = head;
            if (prevHead) {
                prevHead->next = tmp;
            }
            prevHead = head;
            head = head->next;
        }
        return ret;
    }
};

/*
Tips:
*/