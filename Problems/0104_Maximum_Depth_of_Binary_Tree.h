#pragma once

/* 
104. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.



Example 1:
   3
  / \
 /   \
9    20
     / \
    /   \
   15    7
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

Example 3:
Input: root = []
Output: 0

Example 4:
Input: root = [0]
Output: 1


Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

#include <queue>
#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        // 1. Recursive Approach
        // Time complexity:     O(N)
        // Space complexity:    O(lgN)
        //return root ? 1 + std::max(maxDepth(root->left), maxDepth(root->right)) : 0;

        // 2. Iterative Approach with one queue
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        if (!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        while (!q.empty()) {
            ++height;
            int tmpSize = q.size();
            for (size_t i = 0; i < tmpSize; ++i) {
                auto t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return height;

        // 3. Iterative Approach with two queues
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (!root) return 0;
        std::queue<TreeNode*> q;
        std::queue<int> hq;
        int height = 1;
        q.push(root);
        hq.push(height);
        while (!q.empty()) {
            auto t = q.front();
            auto h = hq.front();
            q.pop();
            hq.pop();
            if (t->left) {
                q.push(t->left);
                hq.push(h + 1);
                height = h + 1;
            }
            if (t->right) {
                q.push(t->right);
                hq.push(h + 1);
                height = h + 1;
            }
        }
        return height;*/
    }
};

/*
Tips:
*/