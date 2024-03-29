#pragma once

/*
653. Two Sum IV - Input is a BST
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.



Example 1:
      5
     / \
    /   \
   3     6
  / \     \
 /   \     \
2     4     7
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
      5
     / \
    /   \
   3     6
  / \     \
 /   \     \
2     4     7
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Example 3:
Input: root = [2,1,3], k = 4
Output: true

Example 4:
Input: root = [2,1,3], k = 1
Output: false

Example 5:
Input: root = [2,1,3], k = 3
Output: true


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-10^4 <= Node.val <= 10^4
root is guaranteed to be a valid binary search tree.
-10^5 <= k <= 10^5
*/

#include <stack>
#include <unordered_set>

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
    bool findTarget(TreeNode* root, int k) {
        // 1. Store in a vector and use two pointers
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> v;
        std::stack<TreeNode*> s;
        while (true) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else if (!s.empty()) {
                auto t = s.top();
                s.pop();
                v.push_back(t->val);
                root = t->right;
            }
            else {
                break;
            }
        }
        int i = 0;
        int j = v.size() - 1;
        while (i < j) {
            if (v[i] + v[j] > k) {
                --j;
            }
            else if (v[i] + v[j] < k) {
                ++i;
            }
            else {
                return true;
            }
        }
        return false;*/

        // 2. unordered_set
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        if (!root) return false;
        std::stack<TreeNode*> s;
        std::unordered_set<int> st;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (st.count(t->val)) {
                return true;
            }
            st.insert(k - t->val);
            if (t->left) {
                s.push(t->left);
            }
            if (t->right) {
                s.push(t->right);
            }
        }
        return false;
    }
};

/*
Tips:
*/