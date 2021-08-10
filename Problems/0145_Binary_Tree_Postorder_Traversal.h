#pragma once

/* 
145. Binary Tree Postorder Traversal
https://leetcode.com/problems/binary-tree-postorder-traversal/

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
Output: [3,2,1]

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
Output: [2,1]

Example 5:
1
 \
  \
   2
Input: root = [1,null,2]
Output: [2,1]


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
    void postorder(TreeNode* root, std::vector<int>& v) {
        if (!root) return;
        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->val);
    }

    std::vector<int> postorderTraversal(TreeNode* root) {
        // 1. Recursion
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        /*std::vector<int> v;
        postorder(root, v);
        return v;*/

        // 2. Preorder traversal with iteration and reversal
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> v;
        if (!root) return v;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            v.push_back(t->val);
            if (t->left) {
                s.push(t->left);
            }
            if (t->right) {
                s.push(t->right);
            }
        }
        std::reverse(v.begin(), v.end());
        return v;*/

        // 3. Iteration
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::vector<int> v;
        if (!root) return v;
        std::stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        while (true) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else if (!s.empty()) {
                TreeNode* tmp = s.top();
                if (tmp->right && tmp->right != prev) {
                    root = tmp->right;
                }
                else {
                    v.push_back(tmp->val);
                    prev = tmp;
                    s.pop();
                }
            }
            else {
                break;
            }
        }
        return v;

        // 4. Iteration with double pushing
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> v;
        if(!root) return v;
        std::stack<TreeNode*> s;
        s.push(root);
        s.push(root);
        TreeNode* cur = nullptr;
        while(!s.empty()){
            cur = s.top();
            s.pop();
            if(!s.empty() && s.top() == cur){
                if(cur->right) {
                    s.push(cur->right);
                    s.push(cur->right);
                }
                if(cur->left) {
                    s.push(cur->left);
                    s.push(cur->left);
                }
            }
            else
                v.push_back(cur->val);
        }
        return v;*/
    }
};

/*
Tips:
    1. Solution 3 and 4 uses different method to label whether right children of current node has been visited
*/