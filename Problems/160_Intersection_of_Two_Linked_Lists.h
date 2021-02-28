#pragma once

/* 
160. Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:
          a1 -----> a2 ----->
                               c1 -----> c2 -----> c3
b1 -----> b2 -----> b3 ----->

begin to intersect at node c1.



Example 1:
         4 -----> 1 ----->
                           8 -----> 4 -----> 5
5 -----> 6 -----> 1 ----->

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.


Example 2:
1 -----> 9 -----> 1 ----->
                           2 -----> 4
                  3 ----->

Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.


Example 3:
2 -----> 6 -----> 4
         1 -----> 5

Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Each value on each linked list is in the range [1, 10^9].
Your code should preferably run in O(n) time and use only O(1) memory.
*/

#include <unordered_set>

// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 1. Brute force
        // Time complexity:     O(M * N)
        // Space complexity:    O(1)
        /*while (headA) {
            ListNode* pB = headB;
            while (pB) {
                if (headA == pB) {
                    return pB;
                }
                pB = pB->next;
            }
            headA = headA->next;
        }
        return nullptr;*/

        // 2. Hash table
        // Time complexity:     O(M + N)
        // Space complexity:    O(N)
        /*std::unordered_set<ListNode*> st;
        while (headB) {
            st.insert(headB);
            headB = headB->next;
        }
        while (headA) {
            if (st.find(headA) != st.end()) {
                return headA;
            }
            headA = headA->next;
        }
        return nullptr;*/

        // 3. Two pointers (with knowledge of difference in sizes)
        // Time complexity:     O(M + N)
        // Space complexity:    O(1)
        /*ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA && pB) {
            pA = pA->next;
            pB = pB->next;
        }
        int sizeDiff = 0;
        if (pA) {
            while (pA) {
                pA = pA->next;
                ++sizeDiff;
            }
        }
        else {
            while (pB) {
                pB = pB->next;
                --sizeDiff;
            }
        }
        pA = headA;
        pB = headB;
        if (sizeDiff > 0) {
            while (sizeDiff) {
                pA = pA->next;
                --sizeDiff;
            }
        }
        else {
            while (sizeDiff) {
                pB = pB->next;
                ++sizeDiff;
            }
        }

        while (pA) {
            if (pA == pB) {
                break;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return pA; */

        // 4. Two pointers (without knowledge of difference in sizes)
        // Time complexity:     O(M + N)
        // Space complexity:    O(1)
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA;

        // 5. Reverse and compare (changes the linked list hence not allowed)
        // Time complexity:     O(M + N)
        // Space complexity:    O(1)
        /*if (!headA || !headB) return nullptr;
        ListNode* revA = reverseList(headA);
        ListNode* revB = reverseList(headB);
        ListNode* common = nullptr;
        while (revA && revB) {
            if (revA != revB) {
                break;
            }
            common = revA;
            revA = revA->next;
            revB = revB->next;
        }
        return common;*/
    }
};

/*
Tips:
    1. Time complexity of solution 3 is guaranted to be O(2 * M - I), where M is the length of the longer list and I is the length of the intesection part
    2. Time complexity of solution 4 in best cases is O(M), when the two lists have the same length and do not intersect; in worst case it is O(M + N)
    3. The actual run time of solution 3 is slightly shorter than that of solution 4; this may result from the fact that in most test cases I is large (and therefore O(M - I) < O(N))
*/