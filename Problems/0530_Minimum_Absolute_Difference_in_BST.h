#pragma once

/* 
530. Minimum Absolute Difference in BST
https://leetcode.com/problems/minimum-absolute-difference-in-bst/

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.



Example 1:
      4
     / \
    /   \
   2     6
  / \
 /   \
1     3
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
      1
     / \
    /   \
   0    48
        / \
       /   \
      12   49
Input: root = [1,0,48,null,null,12,49]
Output: 1


Constraints:

The number of nodes in the tree is in the range [2, 10^4].
0 <= Node.val <= 10^5


Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
*/

#include <limits>
#include <stack>
#include <algorithm>

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
    int getMinimumDifference(TreeNode* root) {
        // 1. Inorder traversal with iteration
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        if (!root) return 0;
        int min = std::numeric_limits<int>::max();
        TreeNode* prev = nullptr;
        std::stack<TreeNode*> s;
        while (true) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else if (!s.empty()) {
                auto t = s.top();
                s.pop();
                if (prev) {
                    min = std::min(min, std::abs(t->val - prev->val));
                }
                prev = t;
                root = t->right;
            }
            else {
                break;
            }
        }
        return min;
    }
};

/*
Tips:
*/