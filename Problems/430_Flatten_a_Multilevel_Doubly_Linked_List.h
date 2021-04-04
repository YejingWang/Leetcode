#pragma once

/* 
430. Flatten a Multilevel Doubly Linked List
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.



Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:



After flattening the multilevel linked list it becomes:


Example 2:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL
Example 3:

Input: head = []
Output: []


How multilevel linked list is represented in test case:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]


Constraints:

The number of Nodes will not exceed 1000.
1 <= Node.val <= 105
*/

#include <stack>

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        // 1. Use stack
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::stack<Node*> stk;
        Node* oriHead = head;
        Node* prevHead = head;
        while (head) {
            if (head->child) {
                if (head->next) {
                    stk.push(head->next);
                }
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
            }
            else if (!head->next && !stk.empty()) {
                head->next = stk.top();
                stk.pop();
                if (head->next) {
                    head->next->prev = head;
                }
            }
            head = head->next;
        }
        return oriHead;*/

        // 2. Free of stack
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        for (Node* h = head; h; h = h->next)
        {
            if (h->child)
            {
                Node* next = h->next;
                h->next = h->child;
                h->next->prev = h;
                h->child = NULL;
                Node* p = h->next;
                while (p->next) p = p->next;
                p->next = next;
                if (next) next->prev = p;
            }
        }
        return head;
    }
};

/*
Tips:
    1. Time complexity of the approach 2 is O(N), though with a coefficient, since every node with
    a child will be visited twice
*/