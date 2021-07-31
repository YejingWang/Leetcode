#pragma once

/* 
107. Binary Tree Level Order Traversal II
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).



Example 1:
   3
  / \
 /   \
9     20
      / \
     /   \
    15    7

Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

#include <vector>
#include <queue>
#include <utility>
#include <xutility>

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
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(height(root->left), height(root->right));
    }

    void levelorderbottom(TreeNode* root, std::vector<std::vector<int>>& v, int level) {
        v[level].push_back(root->val);
        if (root->left) levelorderbottom(root->left, v, level - 1);
        if (root->right) levelorderbottom(root->right, v, level - 1);
    }

    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        // 1. Level order traversal and reversal
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<std::vector<int>> v;
        if (!root) return v;
        std::queue<std::pair<int, TreeNode*>> q;
        q.push(std::make_pair(1, root));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (v.size() < t.first) {
                std::vector<int> vt{ t.second->val };
                v.push_back(vt);
            }
            else {
                v[t.first - 1].push_back(t.second->val);
            }
            if (t.second->left) {
                q.push(std::make_pair(t.first + 1, t.second->left));
            }
            if (t.second->right) {
                q.push(std::make_pair(t.first + 1, t.second->right));
            }
        }
        std::reverse(v.begin(), v.end());
        return v;*/

        // 2. Using height and recursion
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        int h = height(root);
        std::vector<std::vector<int>> v(h, std::vector<int>{});
        if (!root) return v;
        levelorderbottom(root, v, h - 1);
        return v;
    }
};

/*
Tips:
*/