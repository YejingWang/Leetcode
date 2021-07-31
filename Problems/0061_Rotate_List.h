#pragma once

/* 
61. Rotate List
https://leetcode.com/problems/reverse-linked-list-ii/

Given the head of a linked list, rotate the list to the right by k places.



Example 1:

            1 -----> 2 -----> 3 -----> 4 -----> 5

rotate 1    5 -----> 1 -----> 2 -----> 3 -----> 4
rotate 2    4 -----> 5 -----> 1 -----> 2 -----> 3

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:

0 -----> 1 -----> 2

rotate 1    2 -----> 0 -----> 1
rotate 2    1 -----> 2 -----> 0
rotate 3    0 -----> 1 -----> 2
rotate 4    2 -----> 0 -----> 1

Input: head = [0,1,2], k = 4
Output: [2,0,1]


Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. Find tail and reconnect
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        if (!head) return head;
        ListNode* pHead = head;
        int cnt = 0;
        while (pHead) {
            ++cnt;
            pHead = pHead->next;
        }
        int rTimes = k % cnt;
        if (rTimes == 0) return head;
        k = cnt - rTimes;
        cnt = 0;
        pHead = head;
        ListNode* post = nullptr;
        while (pHead) {
            ++cnt;
            if (cnt == k) {
                post = pHead->next;
                pHead->next = nullptr;
                break;
            }
            pHead = pHead->next;
        }
        pHead = post;
        cnt = 0;
        while (cnt < rTimes - 1) {
            ++cnt;
            pHead = pHead->next;
        }
        pHead->next = head;
        return post;
    }
};

/*
Tips:
*/