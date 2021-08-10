#pragma once

/* 
872. Leaf-Similar Trees
https://leetcode.com/problems/leaf-similar-trees/

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
       3
      / \
     /   \
    /     \
   5       1
  / \     / \
 /   \   /   \
6     2 9     8
     / \
    /   \
   7     4
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.



Example 1:
       3                 3
      / \               / \
     /   \             /   \
    /     \           /     \
   5       1         5       1
  / \     / \       / \     / \
 /   \   /   \     /   \   /   \
6     2 9     8   6     7 4     2
     / \                       / \
    /   \                     /   \
   7     4                   9     8
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Example 2:
Input: root1 = [1], root2 = [1]
Output: true

Example 3:
Input: root1 = [1], root2 = [2]
Output: false

Example 4:
Input: root1 = [1,2], root2 = [2,2]
Output: true

Example 5:
   1         1
  / \       / \
 /   \     /   \
2     3   3     2
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false


Constraints:

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
*/

#include <vector>
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
    std::vector<int> leaves(TreeNode* root) {
        std::vector<int> v;
        if (!root) return v;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (!t->left && !t->right) {
                v.push_back(t->val);
            }
            if (t->left) {
                s.push(t->left);
            }
            if (t->right) {
                s.push(t->right);
            }
        }
        return std::move(v);
    }

    int dfs(std::stack<TreeNode*>& s) {
        while (true) {
            auto t = s.top();
            s.pop();
            if (!t->left && !t->right) {
                return t->val;
            }
            if (t->left) {
                s.push(t->left);
            }
            if (t->right) {
                s.push(t->right);
            }
        }
        return 0;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // 1. Use vector for memoization
        // Time complexity:     O(N1 + N2)
        // Space complexity:    O(H1 + H2)
        /*std::vector<int> v1 = leaves(root1);
        std::vector<int> v2 = leaves(root2);
        if (v1.size() != v2.size()) {
            return false;
        }
        for (size_t i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;*/

        // 2. Compare in real time
        // Time complexity:     O(N1 + N2)
        // Space complexity:    O(H1 + H2)
        std::stack<TreeNode*> s1, s2;
        s1.push(root1);
        s2.push(root2);
        while (!s1.empty() && !s2.empty()) {
            if (dfs(s1) != dfs(s2)) {
                return false;
            }
        }
        return s1.empty() && s2.empty();
    }
};

/*
Tips:
    1.Solution 2 saves the space of the vector, but O(H1 + H2) space is still needed for traversal
*/