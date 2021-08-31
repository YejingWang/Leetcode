#pragma once

/* 
103. Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).



Example 1:
   3
  / \
 /   \
9    20
     / \
    /   \
   15    7
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

#include <vector>
#include <queue>
#include <deque>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 1. Level order traversal and reversal
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<std::vector<int>> res;
        if (!root) return res;
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            std::vector<int> v;
            for (int i = 0; i < sz; ++i) {
                auto t = q.front();
                q.pop();
                v.push_back(t->val);
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
            if (level % 2 == 0) {
                std::reverse(v.begin(), v.end());
            }
            ++level;
            res.push_back(v);
        }
        return res;*/

        // 2. Level order traversal and in-place placing
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<std::vector<int>> res;
        if (!root) return res;
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            std::vector<int> v(sz);
            for (int i = 0; i < sz; ++i) {
                auto t = q.front();
                q.pop();
                int index = level % 2 ? i : sz - i - 1;
                v[index] = t->val;
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
            ++level;
            res.push_back(v);
        }
        return res;*/

        // 3. Doubly-ended queue
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::vector<std::vector<int>> res;
        if (!root) return res;
        std::deque<TreeNode*> dq;
        dq.push_back(root);
        int level = 1;
        while (!dq.empty()) {
            int sz = dq.size();
            std::vector<int> v(sz);
            for (int i = 0; i < sz; ++i) {
                if (level % 2) {
                    auto t = dq.front();
                    dq.pop_front();
                    v[i] = t->val;
                    if (t->left) {
                        dq.push_back(t->left);
                    }
                    if (t->right) {
                        dq.push_back(t->right);
                    }
                }
                else {
                    auto t = dq.back();
                    dq.pop_back();
                    v[i] = t->val;
                    if (t->right) {
                        dq.push_front(t->right);
                    }
                    if (t->left) {
                        dq.push_front(t->left);
                    }
                }
            }
            ++level;
            res.push_back(v);
        }
        return res;
    }
};

/*
Tips:
*/