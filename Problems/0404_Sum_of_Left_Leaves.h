#pragma once

/* 
404. Sum of Left Leaves
https://leetcode.com/problems/sum-of-left-leaves/

Given the root of a binary tree, return the sum of all left leaves.



Example 1:
   3
  / \
 /   \
9    20
     /\
    /  \
   15   7
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/

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
    int sumOfLL(TreeNode* root, bool isLeft) {
        if (!root) return 0;
        if (isLeft && !root->left && !root->right) return root->val;
        return sumOfLL(root->left, true) + sumOfLL(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        // 1. Iteration
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*int sum = 0;
        if (!root) return sum;
        std::stack<std::pair<TreeNode*, bool>> s;
        s.push(std::make_pair(root, false));
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (t.second && !t.first->left && !t.first->right) {
                sum += t.first->val;
            }
            if (t.first->left) {
                s.push(std::make_pair(t.first->left, true));
            }
            if (t.first->right) {
                s.push(std::make_pair(t.first->right, false));
            }
        }
        return sum;*/

        // 2. Recursion
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        return sumOfLL(root, false);
    }
};

/*
Tips:
*/