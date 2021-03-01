#pragma once

/* 
1669. Merge In Between Linked Lists
https://leetcode.com/problems/merge-in-between-linked-lists/

You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure incidate the result:
                                        -----------------------
                                       |         Remove        |
List1: 0 -----> ... ----->  a-1 -----> | a -----> ... -----> b |-----> b+1 -----> ... -----> n-1
                                        -----------------------
                             ||                                        /\
                             \/                                        ||
List2:                       0 ----->             ...           -----> m-1
Build the result list and return its head.



Example 1:
                                    ------------
                                   |   Remove   |
List1: 0 -----> 1 ----->  2 -----> | 3 -----> 4 |-----> 5
                                    ------------
                          ||                            /\
                          \/                            ||
List2:                 1000000 -----> 1000001 -----> 1000002

Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [0,1,2,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.

Example 2:
                            ----------------------------------
                           |              Remove              |
List1: 0 ------> 1 ------> | 2 ------>  3 ------> 4 ------> 5 |------> 6
                            ----------------------------------
                ||                                                     /\
                \/                                                     ||
List2:       1000000 -----> 1000001 -----> 1000002 -----> 1000003 -> 1000004

Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.


Constraints:

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // 1. Straightforward
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        int pos = 0;
        ListNode* l1 = list1;
        while (pos < a - 1) {
            l1 = l1->next;
            ++pos;
        }
        ListNode* tmp1 = l1;
        while (pos <= b) {
            l1 = l1->next;
            ++pos;
        }
        tmp1->next = list2;
        while (list2->next) {
            list2 = list2->next;
        }
        list2->next = l1;
        return list1;
    }
};

/*
Tips:
*/