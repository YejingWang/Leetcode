#pragma once

/*
206. Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <vector>

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
        // 1. Store to a vector
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> vec;
        ListNode* tmp = head;
        while (tmp) {
            vec.push_back(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        int pos = vec.size() - 1;
        while (tmp) {
            tmp->val = vec[pos--];
            tmp = tmp->next;
        }
        return head;*/

        // 2. Iterative approach
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode* prev = nullptr;
        ListNode* post = head;
        while (post) {
            ListNode* tmp = post->next;
            post->next = prev;
            prev = post;
            post = tmp;
        }
        return prev;*/

        // 3. Iterative approach with virtual header
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode* prev = new ListNode(0, head);
        ListNode* post = head;
        while (post && post->next) {
            ListNode* tmp = prev->next;
            prev->next = post->next;
            post->next = post->next->next;
            prev->next->next = tmp;
        }
        return prev->next;*/

        // 4. Recursive approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        if (!head || !head->next) {
            return head;
        }
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};

/*
Tips:
*/