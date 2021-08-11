#pragma once

/* 
501. Find Mode in Binary Search Tree
https://leetcode.com/problems/find-mode-in-binary-search-tree/

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:
1
 \
  \
   2
  /
 /
2
Input: root = [1,null,2,2]
Output: [2]

Example 2:
Input: root = [0]
Output: [0]


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-10^5 <= Node.val <= 10^5


Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
*/

#include <vector>
#include <unordered_map>
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
    std::vector<int> findMode(TreeNode* root) {
        // 1. Hash table
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::vector<int> v;
        if (!root) return v;
        std::unordered_map<int, int> m;
        int maxOccurs = 0;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            ++m[t->val];
            maxOccurs = m[t->val] > maxOccurs ? m[t->val] : maxOccurs;
            if (t->left) {
                s.push(t->left);
            }
            if (t->right) {
                s.push(t->right);
            }
        }
        for (auto& e : m) {
            if (e.second == maxOccurs) {
                v.push_back(e.first);
            }
        }
        return v;

        // 1. Inorder traversal with recursion
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*                                    TO-DO                                   */
    }
};

/*
Tips:
*/