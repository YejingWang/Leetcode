#pragma once

/* 
226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/

Given the root of a binary tree, invert the tree, and return its root.



Example 1:
       4                    4
      / \                  / \
     /   \                /   \
    /     \     ---\     /     \
   2       7    ---/    7       2
  / \     / \          / \     / \ 
 /   \   /   \        /   \   /   \
1     3 6     9      9     6 3     1
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
   2            2
  / \   ---\   / \
 /   \  ---/  /   \
1     3      3     1

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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
    TreeNode* invertTree(TreeNode* root) {
        // 1. Recursion
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*if (!root) return nullptr;
        auto tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;*/

        // 2. Iteration (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        if (!root) return nullptr;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            auto tmp = t->left;
            t->left = t->right;
            t->right = tmp;
            if (t->left) {
                s.push(t->left);
            }
            if (t->right) {
                s.push(t->right);
            }
        }
        return root;

        // 3. Iteration (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        if (!root) return nullptr;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto tmp = t->left;
            t->left = t->right;
            t->right = tmp;
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
        return root;
    }
};

/*
Tips:
*/