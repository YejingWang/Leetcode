#pragma once

/* 
671. Second Minimum Node In a Binary Tree
https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.





Example 1:
   2
  / \
 /   \
2     5
     / \
    /   \
   5     7
Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

Example 2:
   2
  / \
 /   \
2     2
Input: root = [2,2,2]
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.


Constraints:

The number of nodes in the tree is in the range [1, 25].
1 <= Node.val <= 2^31 - 1
root.val == min(root.left.val, root.right.val) for each internal node of the tree.
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
    int findSecondMinimumValue(TreeNode* root) {
        // 1. Traversal over the entire tree
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*if (!root || !root->right) return -1;

        TreeNode* sMinNode = nullptr;

        std::stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (t->val > root->val) {
                if (!sMinNode || t->val < sMinNode->val )
                sMinNode = t;
            }
            if (t->left) {
                s.push(t->left);
                s.push(t->right);
            }
        }
        if (!sMinNode || sMinNode->val == root->val) {
            return -1;
        }
        return sMinNode->val;*/

        // 2. Traversal with pruning
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        if (!root || !root->right) return -1;

        TreeNode* sMinNode = nullptr;

        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (t->left) {
                if (t->left->val == t->val) {
                    s.push(t->left);
                    if (t->right->val == t->val) {
                        s.push(t->right);
                    }
                    else {
                        if (!sMinNode || sMinNode->val > t->right->val) {
                            sMinNode = t->right;
                        }
                    }
                }
                else {
                    s.push(t->right);
                    if (!sMinNode || sMinNode->val > t->left->val) {
                        sMinNode = t->left;
                    }
                }
            }
        }
        return sMinNode ? sMinNode->val : -1;
    }
};

/*
Tips:
*/