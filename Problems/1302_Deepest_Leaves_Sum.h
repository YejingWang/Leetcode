#pragma once

/* 
1302. Deepest Leaves Sum
https://leetcode.com/problems/deepest-leaves-sum/

Given the root of a binary tree, return the sum of values of its deepest leaves.


Example 1:
         1
        / \
       /   \
      2     3
     / \     \
    /   \     \
   4     5     6
  /             \
 /               \
7                 8
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
1 <= Node.val <= 100
*/

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
    int deepestLeavesSum(TreeNode* root) {
        // 1. Level-order traversal
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        if (!root) return 0;
        int sum = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            sum = 0;
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                auto t = q.front();
                q.pop();
                sum += t->val;
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
        }
        return sum;
    }
};

/*
Tips:
*/