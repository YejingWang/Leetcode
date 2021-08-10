#pragma once

/* 
112. Path Sum
https://leetcode.com/problems/path-sum/

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.



Example 1:
         5
        / \
       /   \
      /     \
     4       8
    /       / \
   /       /   \
  11      13    4
  / \            \
 /   \            \
7     2            1
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true

Example 2:
   1
  / \
 /   \
2     3
Input: root = [1,2,3], targetSum = 5
Output: false

Example 3:
Input: root = [1,2], targetSum = 0
Output: false


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
    bool pathSum(TreeNode* root, int target, int sum) {
        sum += root->val;
        if (!root->left && !root->right) {
            return sum == target;
        }

        bool bl = false;
        if (root->left) {
            bl = pathSum(root->left, target, sum);
        }
        bool br = false;
        if (root->right) {
            br = pathSum(root->right, target, sum);
        }
        return bl || br;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        // 1. Recursion (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        /*if (!root) return false;
        return pathSum(root, targetSum, 0);*/

        // 2. Better recursion (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        if (!root) return false;
        if (root->val == targetSum && !root->left && !root->right) return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);

        // 3. Iteration with stack (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        /*if (!root) return false;

        std::stack<std::pair<TreeNode*, int>> s;
        s.push(std::make_pair(root, 0));
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (!t.first->left && !t.first->right) {
                if (t.second + t.first->val == targetSum) {
                    return true;
                }
            }
            if (t.first->left) {
                s.push(std::make_pair(t.first->left, t.second + t.first->val));
            }
            if (t.first->right) {
                s.push(std::make_pair(t.first->right, t.second + t.first->val));
            }
        }
        return false;*/

        // 4. Iteration with queue (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (!root) return false;

        std::queue<std::pair<TreeNode*, int>> s;
        s.push(std::make_pair(root, 0));
        while (!s.empty()) {
            auto t = s.front();
            s.pop();
            if (!t.first->left && !t.first->right) {
                if (t.second + t.first->val == targetSum) {
                    return true;
                }
            }
            if (t.first->left) {
                s.push(std::make_pair(t.first->left, t.second + t.first->val));
            }
            if (t.first->right) {
                s.push(std::make_pair(t.first->right, t.second + t.first->val));
            }
        }
        return false;*/
    }
};

/*
Tips:
*/