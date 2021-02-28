#pragma once

/* 
203. Remove Linked List Elements
https://leetcode.com/problems/remove-linked-list-elements/

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        // 1. Iterative approach with sentinel node
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        ListNode* sentinel = new ListNode(0, head);
        ListNode* prev = sentinel;
        while (head) {
            if (head->val == val) {
                prev->next = head->next;
            }
            else {
                prev = head;
            }
            head = head->next;
        }
        return sentinel->next;

        // 2. Recursive approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (!head) return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;*/
    }
};

/*
Tips:
*/