#pragma once

/* 
1. Two Sum
https://leetcode.com/problems/two-sum/

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include <vector>

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

    bool isPalindrome(ListNode* head) {
        // 1. Store to a vector
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = v.size() - 1; i < j; ++i, --j) {
            if (v[i] != v[j]) {
                return false;
            }
        }
        return true;*/

        // 2. Two pointers and reversal
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        slow = reverseList(slow);
        while (fast && slow) {
            if (fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};

/*
Tips:
*/