#pragma once

/* 
617. Merge Two Binary Trees
https://leetcode.com/problems/merge-two-binary-trees/

You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.



Example 1:
       1                2                        3
      / \              / \                      / \
     /   \            /   \                    /   \
    3     2          1     3      ---\        4     5
   /\      \          \     \     ---/       /\      \
  /  \      \          \     \              /  \      \
 5    7     18          4     7            5    4      7

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]


Constraints:

The number of nodes in both trees is in the range [0, 2000].
-104 <= Node.val <= 104
*/

#include <queue>

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 1. Recursive approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (!t1) return t2;
        if (!t2) return t1;
        TreeNode* root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;*/

        // 2. Iterative approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        if (!t1) return t2;
        if (!t2) return t1;
        TreeNode* root = new TreeNode(t1->val + t2->val);
        std::queue<TreeNode*> s, s1, s2;
        s.push(root);
        s1.push(t1);
        s2.push(t2);
        while (!s.empty()) {
            TreeNode* pt = s.front();
            TreeNode* pt1 = s1.front();
            TreeNode* pt2 = s2.front();
            s.pop();
            s1.pop();
            s2.pop();
            if (!pt1->left) {
                pt->left = pt2->left;
            }
            else if (!pt2->left) {
                pt->left = pt1->left;
            }
            else {
                pt->left = new TreeNode(pt1->left->val + pt2->left->val);
                s.push(pt->left);
                s1.push(pt1->left);
                s2.push(pt2->left);
            }
            if (!pt1->right) {
                pt->right = pt2->right;
            }
            else if (!pt2->right) {
                pt->right = pt1->right;
            }
            else {
                pt->right = new TreeNode(pt1->right->val + pt2->right->val);
                s.push(pt->right);
                s1.push(pt1->right);
                s2.push(pt2->right);
            }
        }
        return root;
    }
};

/*
Tips:
*/