#pragma once

/* 
138. Copy List with Random Pointer
https://leetcode.com/problems/copy-list-with-random-pointer/

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.



Example 1:

|-------------------------------------------------|
|                         |----------------------||
\/                        |                     \/|
7  ----->  13  ------>  11  ------>  10  ----->  1  ----->  nullptr
|/\         |            /\           |                       /\
||----------|             |-----------|                        |
|--------------------------------------------------------------|

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
          |-|
          \/|
1  ----->  2  -----> n ullptr
|         /\
|----------|

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:

3  ----->  3  ----->  3  -----> nullptr
|/\        |          |          /\/\
||---------|          |-----------| |
|-----------------------------------|
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: The given linked list is empty (null pointer), so return null.


Constraints:

0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random is null or is pointing to some node in the linked list.
*/

#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1. Hashtable and two passes
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*Node* pHead = head;
        Node* dummyHead = new Node(0);
        Node* prev = dummyHead;
        std::unordered_map<Node*, Node*> m;
        while (pHead) {
            Node* newNode = new Node(pHead->val);
            prev->next = newNode;
            m[pHead] = newNode;
            prev = newNode;
            pHead = pHead->next;
        }
        pHead = head;
        prev = dummyHead->next;
        while (pHead) {
            prev->random = pHead->random ? m[pHead->random] : nullptr;
            pHead = pHead->next;
            prev = prev->next;
        }
        return dummyHead->next;*/

        // 2. 'In-place' copy
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        Node* pHead = head;
        while (pHead) {
            Node* tmp = new Node(pHead->val);
            tmp->next = pHead->next;
            pHead->next = tmp;
            pHead = tmp->next;
        }
        pHead = head;
        while (pHead && pHead->next) {
            pHead->next->random = pHead->random ? pHead->random->next : nullptr;
            pHead = pHead->next->next;
        }
        pHead = head;
        Node* dummyHead = new Node(0);
        Node* prev = dummyHead;
        while (pHead && pHead->next) {
            prev->next = pHead->next;
            prev = prev->next;
            pHead->next = pHead->next->next;
            pHead = pHead->next;
        }
        return dummyHead->next;

        // 3. 'In-place' copy version 2
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*Node* pHead = head;
        while (pHead) {
            Node* tmp = new Node(pHead->val);
            tmp->next = pHead->random;
            pHead->random = tmp;
            pHead = pHead->next;
        }
        pHead = head;
        while (pHead) {
            pHead->random->random = pHead->random->next ? pHead->random->next->random : nullptr;
            pHead = pHead->next;
        }
        pHead = head;
        Node* newHead = pHead ? pHead->random : nullptr;
        while (pHead) {
            Node* tmp = pHead->random->next;
            pHead->random->next = pHead->next ? pHead->next->random : nullptr;
            pHead->random = tmp;
            pHead = pHead->next;
        }
        return newHead;*/
    }
};

/*
Tips:
*/