#pragma once

/* 
21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.



Example 1:
1 -----> 2 -----> 4
1 -----> 3 -----> 4
1 -----> 1 -----> 2 -----> 3 -----> 4 -----> 4
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: l1 = [], l2 = []
Output: []

Example 3:
Input: l1 = [], l2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 1. Iterative approach
        // Time complexity:     O(min(M, N))
        // Space complexity:    O(1)
        ListNode* head = new ListNode();
        ListNode* tmp = head;
        while (l1 && l2) {
            if (!l2 || l2->val > l1->val) {
                tmp->next = l1;
                l1 = l1->next;
            }
            else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        tmp->next = !l1 ? l2 : l1;  // needed this step
        return head->next;

        // 2. Recursive approach
        // Time complexity:     O(min(M, N))
        // Space complexity:    O(N)
        /*if (!l1) return l2;
        if (!l2) return l1;
        if (l2->val > l1->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }*/
    }
};

/*
Tips:
*/