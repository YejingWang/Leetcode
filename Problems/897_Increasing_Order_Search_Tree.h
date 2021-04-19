#pragma once

/* 
897. Increasing Order Search Tree
https://leetcode.com/problems/increasing-order-search-tree/

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.



Example 1:
                           1
          5                 \
        /  \                 2
       /    \                 \
      3      6                 3
     /\       \       --\       \
    /  \       \      --/        4
   2    4       8                 \
  /            / \                 5
 /            /   \                 \
1            7     9                 6
                                      \
                                       7
                                        \
                                         8
                                          \
                                           9

Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

Example 2:
   5           1
  / \    --\    \
 /   \   --/     5
1     7           \
                   7

Input: root = [5,1,7]
Output: [1,null,5,null,7]


Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
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
private:
    TreeNode* increasingbst(TreeNode* root, TreeNode* next = nullptr) {
        if (!root) return next;
        TreeNode* res = increasingbst(root->left, root);
        root->left = nullptr;
        root->right = increasingbst(root->right, next);
        return res;
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        // 1. Iterative level traversal
        // Time complexity:     O(N) ?
        // Space complexity:    O(N)
        /*TreeNode* bst = new TreeNode(-1);
        TreeNode* pBst = nullptr;
        TreeNode* prevPBst = nullptr;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            pBst = bst;
            prevPBst = bst;
            bool bInsert = false;
            while (pBst) {
                if (pBst->val > front->val) {
                    TreeNode* tmp = new TreeNode(front->val, nullptr, pBst);
                    prevPBst->right = tmp;
                    bInsert = true;
                    break;
                }
                prevPBst = pBst;
                pBst = pBst->right;
            }
            if (!bInsert) {
                prevPBst->right = new TreeNode(front->val);
            }
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        return bst->right;*/

        // 2. Iterative in-order traversal
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*TreeNode* dummy = new TreeNode(0);
        TreeNode* newTree = dummy;
        std::stack<TreeNode*> s;
        while (true) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else if (!s.empty()) {
                root = s.top();
                s.pop();
                TreeNode* tmp = new TreeNode(root->val);
                newTree->right = tmp;
                newTree = tmp;
                root = root->right;
            }
            else {
                break;
            }
        }
        return dummy->right;*/

        // 3. Recursive in-order traversal
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        return increasingbst(root);
    }
};

/*
Tips:
*/