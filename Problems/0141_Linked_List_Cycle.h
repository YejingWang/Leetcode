#pragma once

/* 
141. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.



Example 1:
3 -----> 2 -----> 0 ------> -4
        ^                   |
        | ----------------  |

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
1 -----> 2
^        |
| ------ |

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
1

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.


Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

#include <unordered_set>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 1. Hast table
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::unordered_set<ListNode*> st;
        while (head) {
            if (st.find(head) != st.end()) {
                return true;
            }
            st.insert(head);
            head = head->next;
        }
        return false;*/

        // 2. Fast and slow pointer
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;

        // 3. Self-deletion
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*ListNode* tmp = nullptr;
        while (head) {
            if (head->next == head) {
                return true;
            }
            tmp = head->next;
            head->next = head;
            head = tmp;
        }
        return false;*/
    }
};

/*
Tips:
    1. In a circle a fast (2 steps at a time) and a slow (1 step at a time) pointer will eventually meet
*/