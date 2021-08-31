#pragma once

/* 
113. Path Sum II
https://leetcode.com/problems/path-sum-ii/

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.



Example 1:
         5
        / \
       /   \
      /     \
     4       8
    /       / \
   /       /   \
  11      13    4
  / \          / \
 /   \        /   \
7     2      5     1
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
   1
  / \
 /   \
2     3
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
    void sum(TreeNode* root, int targetSum, std::vector<int>& curV, std::vector<std::vector<int>>& res) {
        curV.push_back(root->val);
        if (!root->left && !root->right) {
            if (root->val == targetSum) {
                res.push_back(curV);
            }
        }
        else {
            if (root->left) {
                sum(root->left, targetSum - root->val, curV, res);
            }
            if (root->right) {
                sum(root->right, targetSum - root->val, curV, res);
            }
        }
        curV.pop_back();
    }

    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        // 1. Backtracking
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        std::vector<std::vector<int>> res;
        if (!root) return res;
        std::vector<int> curV;
        sum(root, targetSum, curV, res);
        return res;
    }
};

/*
Tips:
*/