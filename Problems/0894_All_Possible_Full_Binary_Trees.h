#pragma once

/* 
894. All Possible Full Binary Trees
https://leetcode.com/problems/all-possible-full-binary-trees/

Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.



Example 1:
   0               0                0                0               0
  / \             / \              / \              / \             / \
 /   \           /   \            /   \            /   \           /   \
0     0         0     0          /     \          0     0         0     0
     / \             / \        0       0        / \             / \
    /   \           /   \      / \     / \      /   \           /   \
   0     0         0     0    /   \   /   \    0     0         0     0
        / \       / \        0     0 0     0        / \       / \
       /   \     /   \                             /   \     /   \
      0     0   0     0                           0     0   0     0
Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

Example 2:
Input: n = 3
Output: [[0,0,0]]


Constraints:

1 <= n <= 20
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
    std::vector<TreeNode*> allPossibleFBT(int n) {
        // 1. Dynamic programming
        // Time complexity:     O(2^N) ?
        // Space complexity:    O(2^N) ?
        if (n % 2 == 0) return std::vector<TreeNode*>{};
        std::vector<std::vector<TreeNode*>> v(n);
        for (int i = 0; i < n; i += 2) {
            if (i == 0) {
                TreeNode* root = new TreeNode(0);
                v[i].push_back(root);
            }
            else {
                for (int j = 0; j < i; j += 2) {
                    auto& lv = v[j];
                    auto& rv = v[i - j - 2];
                    for (size_t l = 0; l < lv.size(); ++l) {
                        for (size_t r = 0; r < rv.size(); ++r) {
                            TreeNode* root = new TreeNode(0, lv[l], rv[r]);
                            v[i].push_back(root);
                        }
                    }
                }
            }

        }
        return v.back();
    }
};

/*
Tips:
*/