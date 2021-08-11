#pragma once

/* 
993. Cousins in Binary Tree
https://leetcode.com/problems/cousins-in-binary-tree/

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.



Example 1:
      1
     / \
    /   \
   2     3
  /
 /
4
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:
   1
  / \
 /   \
2     3
 \     \
  \     \
   4     5
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:
   1
  / \
 /   \
2     3
 \
  \
   4
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false


Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.
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
    bool isCousins(TreeNode* root, int x, int y) {
        // 1. DFS with iteration and parent and height comparison
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*if (root->val == x || root->val == y) return false;
        std::stack<std::pair<std::pair<TreeNode*, int>, TreeNode*>> s;
        s.push(std::make_pair(std::make_pair(root, 0), nullptr));
        int hx = -1, hy = -1;
        TreeNode* px = nullptr;
        TreeNode* py = nullptr;
        while (!s.empty() && (!px || !py)) {
            auto t = s.top();
            s.pop();
            if (t.first.first->val == x) {
                px = t.second;
                hx = t.first.second;
            }
            if (t.first.first->val == y) {
                py = t.second;
                hy = t.first.second;
            }
            if (t.first.first->left) {
                s.push(std::make_pair(std::make_pair(t.first.first->left, t.first.second + 1), t.first.first));
            }
            if (t.first.first->right) {
                s.push(std::make_pair(std::make_pair(t.first.first->right, t.first.second + 1), t.first.first));
            }
        }
        return (hx == hy) && (px != py);*/

        // 2. Level-order traversal
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        bool foundX = false;
        bool foundY = false;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                auto t = q.front();
                q.pop();
                if (t->val == x) {
                    foundX = true;
                }
                if (t->val == y) {
                    foundY = true;
                }
                if (t->left && t->right)
                    if ((t->left->val == x && t->right->val == y) ||
                        (t->left->val == y && t->right->val == x)) {
                        return false;
                    }
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (foundX && foundY) return true;
            if ((!foundX && foundY) || (foundX && !foundY)) return false;
        }
        return false;
    }
};

/*
Tips:
*/