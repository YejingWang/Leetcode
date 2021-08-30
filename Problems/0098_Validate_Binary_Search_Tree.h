#pragma once

/* 
98. Validate Binary Search Tree
https://leetcode.com/problems/validate-binary-search-tree/

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:
   2
  / \
 /   \
1     3
Input: root = [2,1,3]
Output: true

Example 2:
   5
  / \
 /   \
1     4
     / \
    /   \
   3     6
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1
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
    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) return true;
        if ((minNode && minNode->val >= root->val) || (maxNode && maxNode->val <= root->val)) return false;
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }

    bool isValidBST(TreeNode* root) {
        // 1. Iterative in-order traversal
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        std::stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        while (true) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else if (!s.empty()) {
                auto t = s.top();
                s.pop();
                if (!prev || prev->val < t->val) {
                    prev = t;
                    root = t->right;
                }
                else {
                    return false;
                }
            }
            else {
                break;
            }
        }
        return true;

        // 2. Recursion
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*return isValid(root, nullptr, nullptr);*/
    }
};

/*
Tips:
    1. Use TreeNode pointer instead of INT_MAX/INT_MIN to avoid bugs concerning corner cases
*/