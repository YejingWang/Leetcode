#pragma once

/* 
102. Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).



Example 1:
   3
  / \
 /   \
9     20
      / \
     /   \
    15    7
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

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
    void levelorder(TreeNode* root, int l, std::vector<std::vector<int>>& v) {
        if (v.size() < l) {
            std::vector<int> vt{ root->val };
            v.push_back(vt);
        }
        else {
            v[l - 1].push_back(root->val);
        }
        if (root->left) {
            levelorder(root->left, l + 1, v);
        }
        if (root->right) {
            levelorder(root->right, l + 1, v);
        }
    }

    void level(std::queue<TreeNode*>& p, std::queue<TreeNode*>& q, std::vector<std::vector<int>>& v) {
        std::vector<int> vt;
        while (!p.empty()) {
            auto tmp = p.front();
            p.pop();
            vt.push_back(tmp->val);
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
        if (vt.size()) {
            v.push_back(vt);
        }
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        // 1. Iteration with while loop (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<std::vector<int>> v;
        if (!root) return v;
        std::queue<std::pair<int, TreeNode*>> q;
        q.push(std::make_pair(1, root));
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            if (v.size() < tmp.first) {
                std::vector<int> vt{ tmp.second->val };
                v.push_back(vt);
            }
            else {
                v[tmp.first - 1].push_back(tmp.second->val);
            }
            if (tmp.second->left) {
                q.push(std::make_pair(tmp.first + 1, tmp.second->left));
            }
            if (tmp.second->right) {
                q.push(std::make_pair(tmp.first + 1, tmp.second->right));
            }
        }
        return v;*/

        // 2. Iteration with for loop (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<std::vector<int>> v;
        if (!root) return v;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            std::vector<int> lv(s);
            for (int i = 0; i < s; ++i) {
                auto t = q.front();
                q.pop();
                lv[i] = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            v.push_back(lv);
        }
        return v;*/

        // 3. Recursion (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        /*std::vector<std::vector<int>> v;
        if (!root) return v;
        levelorder(root, 1, v);
        return v;*/

        // 4. Iteration with two queues
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::vector<std::vector<int>> v;
        if (!root) return v;
        std::queue<TreeNode*> p, q;
        p.push(root);
        while (!p.empty() || !q.empty()) {
            if (!p.empty()) {
                level(p, q, v);
            }
            else {
                level(q, p, v);
            }
        }
        return v;
    }
};

/*
Tips:
*/