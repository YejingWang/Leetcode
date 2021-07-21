#pragma once

/*
110. Balanced Binary Tree
https://leetcode.com/problems/balanced-binary-tree/

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:
   3
  / \
 /   \
9    20
     / \
    /   \
   15    7
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
         1
        / \
       /   \
      2     2
     / \
    /   \
   3     3
  / \
 /   \
4     4

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4
*/

#include <vector>
#include <map>
#include <unordered_map>
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
    bool balanced = true;

    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(height(root->left), height(root->right));
    }

    int heightWithMemo(TreeNode* root, std::unordered_map<TreeNode*, int>& m) {
        int height = 0;
        if (root) {
            height = 1 + std::max(heightWithMemo(root->left, m), heightWithMemo(root->right, m));
        }
        m[root] = height;
        return height;
    }

    bool isBalancedWithMemo(TreeNode* root, std::unordered_map<TreeNode*, int>& m) {
        if (!root) return true;
        return isBalancedWithMemo(root->left, m) && isBalancedWithMemo(root->right, m)
            && std::abs(m[root->left] - m[root->right]) < 2;
    }

    int heightWithFlag(TreeNode* root) {
        if (!root) return 0;
        int lHeight = heightWithFlag(root->left);
        if (lHeight < 0) return -1;
        int rHeight = heightWithFlag(root->right);
        if (rHeight < 0) return -1;
        if (std::abs(lHeight - rHeight) > 1) return -1;
        return 1 + std::max(lHeight, rHeight);
    }

    int heightWithGlobalFlag(TreeNode* root) {
        if (!balanced) return 0;
        if (!root) return 0;
        int lHeight = heightWithGlobalFlag(root->left);
        int rHeight = heightWithGlobalFlag(root->right);
        if (std::abs(lHeight - rHeight) > 1) {
            balanced = false;
        }
        return 1 + std::max(lHeight, rHeight);
    }

    bool isBalanced(TreeNode* root) {
        // 1. Multiple-pass recursion
        // Time complexity:     O(N^2)
        // Space complexity:    O(lgN)
        /*if (!root) return true;
        return isBalanced(root->left) && isBalanced(root->right)
            && std::abs(height(root->left) - height(root->right)) < 2;*/

        // 2. One-pass recursion with unordered_map
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (!root) return true;
        std::unordered_map<TreeNode*, int> m;
        m[nullptr] = 0;
        int height = heightWithMemo(root, m);
        return isBalancedWithMemo(root, m);*/

        // 3. One-pass recursion with -1 as a flag
        // Time complexity:     O(N)
        // Space complexity:    O(lgN)
        //return heightWithFlag(root) >= 0;

        // 4. One-pass recursion with a global flag
        // Time complexity:     O(N)
        // Space complexity:    O(lgN)
        int height = heightWithGlobalFlag(root);
        return balanced;
    }
};

/*
Tips:
*/