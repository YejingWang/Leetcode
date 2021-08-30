#pragma once

/* 
95. Unique Binary Search Trees II
https://leetcode.com/problems/unique-binary-search-trees-ii/

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.



Example 1:
1      1            2            3      3
 \      \          / \          /      /
  \      \        /   \        /      /
   3      2      1     3      2      1
  /        \                 /        \
 /          \               /          \
2            3             1            2
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:
Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 8
*/

#include <vector>

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
    TreeNode* copy(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = copy(root->left);
        newRoot->right = copy(root->right);
        return newRoot;
    }

    void insert(TreeNode* root, int k, std::vector<TreeNode*>& v) {
        TreeNode* r = new TreeNode(k, root, nullptr);
        v.push_back(r);
        TreeNode* tmp = root;
        int cnt = 0;
        while (tmp) {
            v.push_back(copy(root));
            tmp = tmp->right;
            ++cnt;
        }
        for (int i = 0; i < cnt; ++i) {
            TreeNode* cur = v[v.size() - cnt + i];
            int j = 0;
            while (j < i) {
                cur = cur->right;
                ++j;
            }
            TreeNode* newNode = new TreeNode(k, cur->right, nullptr);
            cur->right = newNode;
        }
    }

    std::vector<TreeNode*> generate(int start, int end) {
        std::vector<TreeNode*> v;
        if (start > end) {
            v.push_back(nullptr);
        }
        for (int i = start; i <= end; ++i) {
            std::vector<TreeNode*> leftList = generate(start, i - 1);
            std::vector<TreeNode*> rightList = generate(i + 1, end);
            for (auto l : leftList) {
                for (auto r : rightList) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);
                }
            }
        }
        return v;
    }

    std::vector<TreeNode*> generateTrees(int n) {
        // 1. Dynamic programming
        // Time complexity:     O(N * C(N)) ?
        // Space complexity:    O(N * C(N)) ?
        /*std::vector<std::vector<TreeNode*>> v(n);
        v[0] = std::vector<TreeNode*>{ new TreeNode(1) };
        for (size_t i = 1; i < n; ++i) {
            std::vector<TreeNode*> curV;
            for (size_t j = 0; j < v[i - 1].size(); ++j) {
                insert(v[i - 1][j], i + 1, curV);
            }
            v[i] = curV;
        }
        return v.back();*/

        // 2. Better DP (uses swap to save space)
        // Time complexity:     O(N * C(N)) ?
        // Space complexity:    O(1)
        /*std::vector<TreeNode*> v;
        v.push_back(new TreeNode(1));
        for (size_t i = 1; i < n; ++i) {
            std::vector<TreeNode*> tmp;
            for (size_t j = 0; j < v.size(); ++j) {
                insert(v[j], i + 1, tmp);
            }
            v.swap(tmp);
        }
        return v;*/

        // 3. DFS with DP
        // Time complexity:     O(N * C(N)) ?
        // Space complexity:    O(N)
        return generate(1, n);
    }
};

/*
Tips:
    1. N-th Catalan number C(N) = (2N)! / ((N+1)! * N!)
*/