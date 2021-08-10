#pragma once

/* 
965. Univalued Binary Tree
https://leetcode.com/problems/univalued-binary-tree/

A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.



Example 1:
       1
      / \
     /   \
    /     \
   1       1
  / \     / \
 /   \   /   \
1     1 1     1
Input: root = [1,1,1,1,1,null,1]
Output: true

Example 2:
      2
     / \
    /   \
   2     2
  / \
 /   \
5     2

Input: root = [2,2,2,5,2]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val < 100
*/

#include <stack>
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
    bool isUnivalTree(TreeNode* root) {
        // 1. Recursion (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        if (!root) return true;
        bool bl = (!root->left) || (root->left->val == root->val &&  isUnivalTree(root->left));
        bool br = (!root->right) || (root->right->val == root->val &&  isUnivalTree(root->right));
        return bl && br;

        // 2. Iteration (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*if (!root) return true;
        int uni = root->val;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            if (t->val != uni) {
                return false;
            }
            s.pop();
            if (t->left) {
                s.push(t->left);
            }
            if (t->right) {
                s.push(t->right);
            }
        }
        return true;*/

        // 3. Iteration (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (!root) return true;
        int uni = root->val;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            if (t->val != uni) {
                return false;
            }
            q.pop();
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
        return true;*/
    }
};

/*
Tips:
*/