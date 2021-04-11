#pragma once

/* 
19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?



Example 1:

1 -----> 2 -----> 3 -----> 4 -----> 5
                 ||
                 ||
                 \/
1 -----> 2 -----> 3 --------------> 5

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Two passes
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode* dummyHead = new ListNode(0, head);
        int size = 0;
        while (head) {
            ++size;
            head = head->next;
        }
        int cnt = 0;
        head = dummyHead;
        while (head) {
            if (cnt == size - n) {
                head->next = head->next->next;
                break;
            }
            head = head->next;
            ++cnt;
        }
        return dummyHead->next;*/

        // 2. One pass
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while (fast) {
            fast = fast->next;
            if (n >= 0) {
                --n;
            }
            else {
                slow = slow->next;
            }
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};

/*
Tips:
*/