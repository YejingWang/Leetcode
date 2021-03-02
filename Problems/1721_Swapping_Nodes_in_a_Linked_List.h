#pragma once

/* 
1721. Swapping Nodes in a Linked List
https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).



Example 1:
          ---
1 -----> | 2 | -----> 3 -----> 4 -----> 5
          ---
                               ---
1 ----->   4  -----> 3 -----> | 2 | -----> 5
                               ---
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

Example 3:
Input: head = [1], k = 1
Output: [1]

Example 4:
Input: head = [1,2], k = 1
Output: [2,1]

Example 5:
Input: head = [1,2,3], k = 2
Output: [1,2,3]


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
*/

#include <algorithm>

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
    ListNode* swapNodes(ListNode* head, int k) {
        // 1. Three passes
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*int sz = 0;
        ListNode* tmp = head;
        while (tmp) {
            ++sz;
            tmp = tmp->next;
        }
        if (k == sz- k + 1) return head;
        tmp = head;
        int valFront = -1;
        int valBack = -1;
        int count = 0;
        while (tmp) {
            ++count;
            if (count == k) {
                valFront = tmp->val;
            }
            else if (count == sz - k + 1) {
                valBack = tmp->val;
            }
            tmp = tmp->next;
        }
        tmp = head;
        count = 0;
        while (tmp) {
            ++count;
            if (count == k) {
                tmp->val = valBack;
            }
            else if (count == sz - k + 1) {
                tmp->val = valFront;
            }
            tmp = tmp->next;
        }
        return head;*/

        // 2. One pass
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        ListNode* fast = nullptr;
        ListNode* slow = nullptr;
        for (ListNode* l = head; l; l = l->next) {
            slow = slow ? slow->next : nullptr;
            if (--k == 0) {
                fast = l;
                slow = head;
            }
        }
        std::swap(fast->val, slow->val);
        return head;
    }
};

/*
Tips:
    1. Actual time complexity of approach 1 is O(3N) (can be optimized to be O(2N) < O() < O(3N));
    in approach 2 it is O(N)
    2. Two pointers can be used to get the kth node from both the front and the end:
    the second pointer starts to move when the first pointer reaches the kth node from the front;
    the second pointer reaches the kth node from the end when the first pointer reaches the end
*/