#pragma once

/* 
543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



Example 1:
      1
     / \
    /   \
   2     3
  / \
 /   \
4     5
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-100 <= Node.val <= 100
*/

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
    int diameter(TreeNode* root, int& maxDepthLeft, int& maxRightDepth) {
        if (!root) {
            maxDepthLeft = -1;
            maxRightDepth = -1;
            return 0;
        }
        int mldl, mrdl, mldr, mrdr;
        int dl = diameter(root->left, mldl, mrdl);
        int dr = diameter(root->right, mldr, mrdr);
        maxDepthLeft = 1 + std::max(mldl, mrdl);
        maxRightDepth = 1 + std::max(mldr, mrdr);
        return std::max(std::max(maxDepthLeft + maxRightDepth, dl), dr);
    }

    int depth(TreeNode* root, int& diameter) {
        if (!root) {
            return 0;
        }

        int dpl = depth(root->left, diameter);
        int dpr = depth(root->right, diameter);
        diameter = std::max(diameter, dpl + dpr);
        return 1 + std::max(dpl, dpr);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // 1. Recursion
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*int ml, mr;
        return diameter(root, ml, mr);*/

        // 2. Clearer recursion
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        int dm = 0;
        depth(root, dm);
        return dm;
    }
};

/*
Tips:
*/