#pragma once

/* 
111. Minimum Depth of Binary Tree
https://leetcode.com/problems/minimum-depth-of-binary-tree/

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.



Example 1:
   3
  / \
 /   \
9     20
      / \
     /   \
    15    7
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5


Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
*/

#include <vector>
#include <limits>
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
    int mindepth(TreeNode* root) {
        if (!root->left && !root->right) return 1;
        int dl = std::numeric_limits<int>::max();
        int dr = std::numeric_limits<int>::max();
        if (root->left) dl = minDepth(root->left);
        if (root->right) dr = minDepth(root->right);
        return std::min(dl, dr) + 1;
    }

    int minDepth(TreeNode* root) {
        // 1. Recursion 
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst casr O(N)
        /*if (!root) return 0;
        return mindepth(root);*/

        // 2. Recursion without helper function
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst casr O(N)
        /*if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + std::min(minDepth(root->left), minDepth(root->right));*/

        // 3. Iteration with stack (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst casr O(N)
        /*if (!root) return 0;
        int md = std::numeric_limits<int>::max();
        std::stack<std::pair<TreeNode*, int>> s;
        s.push(std::make_pair(root, 1));
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (!t.first->left && !t.first->right) {
                md = t.second < md ? t.second : md;
            }
            if (t.first->left) {
                s.push(std::make_pair(t.first->left, t.second + 1));
            }
            if (t.first->right) {
                s.push(std::make_pair(t.first->right, t.second + 1));
            }
        }
        return md;*/

        // 4. Iteration with queue (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst casr O(N)
        if (!root) return 0;
        int depth = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++depth;
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                auto t = q.front();
                q.pop();
                if (!t->left && !t->right) return depth;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return depth;
    }
};

/*
Tips:
    1. The input can be very imbalanced, so BFS runs faster
*/