#pragma once

/* 
86. Partition List
https://leetcode.com/problems/partition-list/

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.



Example 1:

1 -----> 4 -----> 3 -----> 2 -----> 5 -----> 2
         -       -                  -
                     ||
                     ||
                     \/
1 -----> 2 -----> 2 -----> 4 -----> 3 -----> 5
                           -       -         -

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]


Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        // 1. Free of dummy nodes
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode* pHead = head;
        ListNode* prev = nullptr;
        ListNode* post = new ListNode(-1);
        ListNode* postHead = post;
        while (pHead) {
            if (pHead->val >= x) {
                post->next = pHead;
                if (prev) {
                    prev->next = pHead->next;
                }
                pHead = pHead->next;
                post = post->next;
                post->next = nullptr;
            }
            else {
                if (!prev) {
                    head = pHead;
                }
                prev = pHead;
                pHead = pHead->next;
            }
        }
        if (prev) {
            prev->next = postHead->next;
        }
        return head;*/

        // 2. Use dummy nodes
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        ListNode* prev = new ListNode(0);
        ListNode* prevHead = prev;
        ListNode* post = new ListNode(0);
        ListNode* postHead = post;
        while (head) {
            if (head->val >= x) {
                post->next = head;
                post = post->next;
            }
            else {
                prev->next = head;
                prev = prev->next;
            }
            head = head->next;
        }
        post->next = nullptr;
        prev->next = postHead->next;
        return prevHead->next;
    }
};

/*
Tips:
*/