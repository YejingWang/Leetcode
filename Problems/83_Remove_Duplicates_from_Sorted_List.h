#pragma once

/* 
83. Remove Duplicates from Sorted List
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.



Example 1:
1 -----> 1 -----> 2
1 -----> 2

Input: head = [1,1,2]
Output: [1,2]

Example 2:
1 -----> 1 -----> 2 -----> 3 -----> 3
1 -----> 2 -----> 3

Input: head = [1,1,2,3,3]
Output: [1,2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        // 1. Iterative approach
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            else {
                cur = cur->next;
            }
        }
        return head;

        // 2. Recursive approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (head && deleteDuplicates(head->next)) {
            if (head->val == head->next->val) {
                head->next = head->next->next;
            }
        }
        return head;*/
    }
};

/*
Tips:
*/