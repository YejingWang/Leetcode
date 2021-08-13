#pragma once

/* 
572. Subtree of Another Tree
https://leetcode.com/problems/subtree-of-another-tree/

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.



Example 1:
     root    subRoot

      3
     / \
    /   \
   4     5      4
  / \          / \
 /   \        /   \
1     2      1     2
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
     root    subRoot

      3
     / \
    /   \
   4     5      4
  / \          / \
 /   \        /   \
1     2      1     2
     /
    /
   0
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false


Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-10^4 <= root.val <= 10^4
-10^4 <= subRoot.val <= 10^4
*/

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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;
        if (r1->val != r2->val) return false;
        return isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 1. Iteration
        // Time complexity:     O(N * M)
        // Space complexity:    O(MAX(Hn, Hm))
        if (!root) return false;
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

/*
Tips:
*/