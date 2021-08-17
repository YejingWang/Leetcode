#pragma once

/* 
1448. Count Good Nodes in Binary Tree
https://leetcode.com/problems/two-sum/

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.



Example 1:
       3
      / \
     /   \
    /     \
   1       4
  /       / \
 /       /   \
3       1     5
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:
       3
      /
     /
    /
   3
  / \
 /   \
4     2
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good.


Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
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
    int good(TreeNode* root, int max) {
        if (!root) return 0;
        int cur = 0;
        if (root->val >= max) {
            max = root->val;
            ++cur;
        }
        return cur + good(root->left, max) + good(root->right, max);
    }

    int goodNodes(TreeNode* root) {
        // 1. DFS with iteration
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        if (!root) return 0;
        int cnt = 0;
        std::stack<std::pair<TreeNode*, int>> s;
        s.push(std::make_pair(root, root->val));
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            int max = t.second;
            if (t.first->val >= t.second) {
                max = t.first->val;
                ++cnt;
            }
            if (t.first->left) {
                s.push(std::make_pair(t.first->left, max));
            }
            if (t.first->right) {
                s.push(std::make_pair(t.first->right, max));
            }
        }
        return cnt;

        // 2. BFS with iteration
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*if (!root) return 0;
        int cnt = 0;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push(std::make_pair(root, root->val));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int max = t.second;
            if (t.first->val >= t.second) {
                max = t.first->val;
                ++cnt;
            }
            if (t.first->left) {
                q.push(std::make_pair(t.first->left, max));
            }
            if (t.first->right) {
                q.push(std::make_pair(t.first->right, max));
            }
        }
        return cnt;*/

        // 3. DFS with recursion
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*return good(root, root->val);*/
    }
};

/*
Tips:
*/