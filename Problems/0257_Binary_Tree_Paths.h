#pragma once

/* 
257. Binary Tree Paths
https://leetcode.com/problems/binary-tree-paths/

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.



Example 1:
   1
  / \
 /   \
2     5
 \
  \
   3
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]


Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/

#include <vector>
#include <string>
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
    void paths(TreeNode* root, std::vector<std::string>& v, std::string path) {
        if (!root->left && !root->right) {
            v.push_back(path);
            return;
        }
        if (root->left) paths(root->left, v, path + "->" + std::to_string(root->left->val));
        if (root->right) paths(root->right, v, path + "->" + std::to_string(root->right->val));
    }

    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        // 1. Recursion without helper function (DFS)
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        /*if (!root->left && !root->right) return std::vector<std::string>{std::to_string(root->val)};
        std::vector<std::string> v;
        if (root->left) {
            auto lv = binaryTreePaths(root->left);
            for (size_t i = 0; i < lv.size(); ++i) {
                v.push_back(std::to_string(root->val) + "->" + lv[i]);
            }
        }
        if (root->right) {
            auto lr = binaryTreePaths(root->right);
            for (size_t i = 0; i < lr.size(); ++i) {
                v.push_back(std::to_string(root->val) + "->" + lr[i]);
            }
        }
        return v;*/

        // 2. Recursion with helper function (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*std::vector<std::string> v;
        if (!root) return v;
        paths(root, v, std::to_string(root->val));
        return v;*/

        // 3. Iteration with stack (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        std::vector<std::string> v;
        if (!root) return v;
        std::stack<std::pair<TreeNode*, std::string>> s;
        s.push(std::make_pair(root, std::to_string(root->val)));
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (!t.first->left && !t.first->right) {
                v.push_back(t.second);
            }
            if (t.first->right) {
                s.push(std::make_pair(t.first->right, t.second + "->" + std::to_string(t.first->right->val)));
            }
            if (t.first->left) {
                s.push(std::make_pair(t.first->left, t.second + "->" + std::to_string(t.first->left->val)));
            }
        }
        return v;

        // 4. Iteration with queue (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<std::string> v;
        if (!root) return v;
        std::queue<std::pair<TreeNode*, std::string>> q;
        q.push(std::make_pair(root, std::to_string(root->val)));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (!t.first->left && !t.first->right) {
                v.push_back(t.second);
            }
            if (t.first->left) {
                q.push(std::make_pair(t.first->left, t.second + "->" + std::to_string(t.first->left->val)));
            }
            if (t.first->right) {
                q.push(std::make_pair(t.first->right, t.second + "->" + std::to_string(t.first->right->val)));
            }
        }
        return v;*/
    }
};

/*
Tips:
*/