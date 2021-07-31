#pragma once

/* 
143. Reorder List
https://leetcode.com/problems/reorder-list/

You are given the head of a singly linked-list. The list can be represented as:

L0 ¡ú L1 ¡ú ¡­ ¡ú Ln - 1 ¡ú Ln
Reorder the list to be on the following form:

L0 ¡ú Ln ¡ú L1 ¡ú Ln - 1 ¡ú L2 ¡ú Ln - 2 ¡ú ¡­
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example 1:

1 -----> 2 -----> 3 -----> 4
             ||
             \/
1 -----> 4 -----> 2 -----> 3

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:

1 -----> 2 -----> 3 -----> 4 -----> 5
                 ||
                 \/
1 -----> 5 -----> 2 -----> 4 -----> 3

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]


Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
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
        ListNode* tmp = nullptr;
        while (post) {
            tmp = post->next;
            post->next = prev;
            prev = post;
            post = tmp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // 1. Extraction (4 passes)
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode* prev = head;
        ListNode* tmp = nullptr;
        int sum = 0;
        while (prev) {
            ++sum;
            prev = prev->next;
        }
        prev = head;
        for (int i = 0; i < (sum + 1) / 2; ++i) {
            tmp = prev;
            prev = prev->next;
        }
        tmp->next = nullptr;
        ListNode* post = reverseList(prev);
        prev = head;
        while (post) {
            tmp = prev->next;
            prev->next = post;
            post = post->next;
            prev->next->next = tmp;
            prev = prev->next->next;
        }*/

        // 2. Extraction (3 passes)
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode* prev = head;
        ListNode* post = head;
        ListNode* tmp = nullptr;
        int sum = 0;
        while (post && post->next) {
            tmp = prev;
            prev = prev->next;
            post = post->next->next;
        }
        if (post) {
            prev = prev->next;
            tmp = tmp->next;
        }
        tmp-> next = nullptr;
        post = reverseList(prev);
        prev = head;
        while (post) {
            tmp = prev->next;
            prev->next = post;
            post = post->next;
            prev->next->next = tmp;
            prev = prev->next->next;
        }*/

        // 3. 3 passes with no extraction
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        //1->2->3->4->5->6 to 1->2->3->6->5->4
        ListNode* preMiddle = p1;
        ListNode* preCurrent = p1->next;
        while (preCurrent && preCurrent->next) {
            ListNode* current = preCurrent->next;
            preCurrent->next = current->next;
            current->next = preMiddle->next;
            preMiddle->next = current;
        }

        //1->2->3->6->5->4 to 1->6->2->5->3->4
        p1 = head;
        p2 = preMiddle->next;
        while (p1 != preMiddle) {
            preMiddle->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = preMiddle->next;
        }
    }
};

/*
Tips:
*/