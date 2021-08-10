#pragma once

/* 
144. Binary Tree Preorder Traversal
https://leetcode.com/problems/binary-tree-preorder-traversal/

Given the root of a binary tree, return the preorder traversal of its nodes' values.



Example 1:
1
 \
  \
   2
  /
 /
3
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
   1
  /
 /
2
Input: root = [1,2]
Output: [1,2]

Example 5:
1
 \
  \
   2
Input: root = [1,null,2]
Output: [1,2]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <vector>
#include <stack>

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
    void visitAlongLeftBranch(TreeNode* root, std::stack<TreeNode*>& s, std::vector<int>& v) {
        while (root) {
            if (root->right) {
                s.push(root->right);
            }
            v.push_back(root->val);
            root = root->left;
        }
    }

    void preOrder(TreeNode* root, std::vector<int>& v) {
        if (!root) return;
        v.push_back(root->val);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        // 1. Iteration
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        std::vector<int> v;
        if (!root) return v;
        std::stack<TreeNode*> s;
        while (true) {
            if (root) {
                s.push(root);
                v.push_back(root->val);
                root = root->left;
            }
            else if (!s.empty()) {
                root = s.top();
                s.pop();
                root = root->right;
            }
            else {
                break;
            }
        }
        return v;

        // 2. Iteration with a helper function
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        /*std::vector<int> v;
        if (!root) return v;
        std::stack<TreeNode*> s;
        while (true) {
            visitAlongLeftBranch(root, s, v);
            if (s.empty()) break;
            root = s.top();
            s.pop();
        }
        return v;*/

        // 3. Easier Iteration
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        std::vector<int> v;
        if (!root) return v;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            v.push_back(t->val);
            if (t->right) {
                s.push(t->right);
            }
            if (t->left) {
                s.push(t->left);
            }
        }
        return v;

        // 4. Recursion
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        /*std::vector<int> v;
        preOrder(root, v);
        return v;*/
    }
};

/*
Tips:
*/