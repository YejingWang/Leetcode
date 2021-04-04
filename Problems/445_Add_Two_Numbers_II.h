#pragma once

/* 
445. Add Two Numbers II
https://leetcode.com/problems/add-two-numbers-ii/

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* post = head;
        while (post) {
            ListNode* tmp = post->next;
            post->next = prev;
            prev = post;
            post = tmp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1. Reverse without header node
        // Time complexity:     O(M+N)
        // Space complexity:    O(1)
        /*ListNode* rl1 = reverseList(l1);
        ListNode* rl2 = reverseList(l2);
        ListNode* l = nullptr;
        ListNode* lTail = nullptr;
        int sup = 0;
        while (rl1 || rl2) {
            int sum = sup;
            if (rl1) {
                sum += rl1->val;
                rl1 = rl1->next;
            }
            if (rl2) {
                sum += rl2->val;
                rl2 = rl2->next;
            }
            sup = sum / 10;
            if (l) {
                l->next = new ListNode(sum % 10);
                l = l->next;
            }
            else {
                l = new ListNode(sum % 10);
                lTail = l;
            }
        }
        if (sup) {
            l->next = new ListNode(sup % 10);
        }
        return reverseList(lTail);*/

        // 2. Reverse with header node
        // Time complexity:     O(M+N)
        // Space complexity:    O(1)
        ListNode* rl1 = reverseList(l1);
        ListNode* rl2 = reverseList(l2);
        ListNode* l = new ListNode(0);
        ListNode* lTail = l;
        int sup = 0;
        while (rl1 || rl2) {
            int sum = sup;
            if (rl1) {
                sum += rl1->val;
                rl1 = rl1->next;
            }
            if (rl2) {
                sum += rl2->val;
                rl2 = rl2->next;
            }
            sup = sum / 10;
            l->next = new ListNode(sum % 10);
            l = l->next;
        }
        if (sup) {
            l->next = new ListNode(sup % 10);
        }
        return reverseList(lTail->next);

        // 3. Stack
        // Time complexity:     O(M+N)
        // Space complexity:    O(M+N)
        /*std::stack<int> s1, s2;
        ListNode* pl1 = l1;
        ListNode* pl2 = l2;
        while (pl1) {
            s1.push(pl1->val);
            pl1 = pl1->next;
        }
        while (pl2) {
            s2.push(pl2->val);
            pl2 = pl2->next;
        }
        int sup = 0;
        ListNode* l = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            int sum = sup;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            sup = sum / 10;
            ListNode* post = new ListNode(sum % 10, l->next);
            l->next = post;
        }
        if (sup) {
            ListNode* post = new ListNode(sup % 10, l->next);
            l->next = post;
        }
        return l->next; */
    }
};

/*
Tips:
*/