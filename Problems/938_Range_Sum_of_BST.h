#pragma once

/* 
938. Range Sum of BST
https://leetcode.com/problems/two-sum/

Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].



Example 1:
       10
      /  \
     /    \
    5      15
   /\       \
  /  \       \
 3    7      18

Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32

Example 2:

         10
        /  \
       /    \
      5      15
     /\      /\
    /  \    /  \
   3    7  13  18
  /    /
 /    /
1    6

Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23


Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
*/

#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        // 1. Iterative approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::queue<TreeNode*> q;
        int sum = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->val >= L && tmp->val <= R) {
                sum += tmp->val;
            }
            if (tmp->left && tmp->val >= L) {
                q.push(tmp->left);
            }
            if (tmp->right && tmp->val <= R) {
                q.push(tmp->right);
            }
        }

        return sum;

        // 2. Recursive approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (!root) return 0;
        if (root->val < L) return rangeSumBST(root->right, L, R);
        if (root->val > R) return rangeSumBST(root->left, L, R);
        return root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R);*/
    }
};

/*
Tips:
*/