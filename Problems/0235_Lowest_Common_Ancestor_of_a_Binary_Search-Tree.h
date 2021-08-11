#pragma once

/* 
235. Lowest Common Ancestor of a Binary Search Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).¡±



Example 1:
       6
      / \
     /   \
    /     \
   2       8
  / \     / \
 /   \   /   \
0     4 7     9
     / \
    /   \
   3     5
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
       6
      / \
     /   \
    /     \
   2       8
  / \     / \
 /   \   /   \
0     4 7     9
     / \
    /   \
   3     5
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2


Constraints:

The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the BST.
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
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q, bool& bp, bool& bq) {
        if (!root) {
            bp = false;
            bq = false;
            return nullptr;
        }
        bool lbp, lbq, rbp, rbq;
        if (auto lca = findLCA(root->left, p, q, lbp, lbq)) {
            return lca;
        }
        if (auto lca = findLCA(root->right, p, q, rbp, rbq)) {
            return lca;
        }
        bp = lbp || rbp || (root == p);
        bq = lbq || rbq || (root == q);
        if (bp && bq) {
            return root;
        }
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1. Recursion withouting using bst
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*bool bp, bq;
        return findLCA(root, p, q, bp, bq);*/

        // 2. Binary search
        // Time complexity:     O(lgN)
        // Space complexity:    O(1)
        while (true) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val) {

                root = root->right;
            }
            else {
                break;
            }
        }
        return root;
    }
};

/*
Tips:
*/