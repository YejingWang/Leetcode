#pragma once

/* 
700. Search in a Binary Search Tree
https://leetcode.com/problems/search-in-a-binary-search-tree/

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.



Example 1:
      4
     / \
    /   \
   2     7
  / \
 /   \
1     3
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:
      4
     / \
    /   \
   2     7
  / \
 /   \
1     3
Input: root = [4,2,7,1,3], val = 5
Output: []


Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 10^7
root is a binary search tree.
1 <= val <= 10^7
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
    TreeNode* searchBST(TreeNode* root, int val) {
        // 1. Iterative approach
        // Time complexity:     O(logN)
        // Space complexity:    O(1)
        while (root && root->val != val) {
            root = root->val > val ? root->left : root->right;
        }
        return root;

        // 2. Recursive approach
        // Time complexity:     O(logN)
        // Space complexity:    O(logN)
        /*if (!root) return nullptr;
        if (root->val == val) {
            return root;
        }
        else {
            return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
        }*/
    }
};

/*
Tips:
*/