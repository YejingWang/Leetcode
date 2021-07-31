#pragma once

/* 
92. Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii/

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.



Example 1:

1 -----> 2 -----> 3 -----> 4 -----> 5
                 ||
                 ||
                 \/
1 -----> 4 -----> 3 -----> 2 -----> 5

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]


Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n


Follow up: Could you do it in one pass?
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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 1. Iterative approach
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode* dummyHead = new ListNode(0, head);
        ListNode* pHead = dummyHead;
        ListNode* prevTail = nullptr;
        ListNode* postHead = nullptr;
        int cnt = 0;
        while (pHead) {
            if (cnt == left - 1) {
                prevTail = pHead;
            }
            if (cnt == right) {
                postHead = pHead->next;
                break;
            }
            ++cnt;
            pHead = pHead->next;
        }
        pHead->next = nullptr;
        ListNode* reverseTail = prevTail->next;
        ListNode* reverseHead = reverseList(reverseTail);
        prevTail->next = reverseHead;
        reverseTail->next = postHead;
        return dummyHead->next;*/

        // 2. (Slightly) better iterative approach
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode *dummy = new ListNode(0);
        ListNode* pre = dummy;
        ListNode* cur = nullptr;;
        dummy->next = head;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        cur = pre->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
        }
        return dummy->next;*/

        // 3. Recursive approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        if (left == right) return head;

        if (left > 1) {
            head->next = reverseBetween(head->next, left - 1, right - 1);
            return head;
        }
        else {
            ListNode* tailNode = reverseBetween(head->next, 1, right - 1);
            ListNode* tailNodeNext = head->next->next;
            head->next->next = head;
            head->next = tailNodeNext;
            return tailNode;
        }
    }
};

/*
Tips:
*/