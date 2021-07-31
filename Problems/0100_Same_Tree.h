#pragma once

/*
94. Binary Tree Inorder Traversal
https://leetcode.com/problems/same-tree/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



Example 1:
   1       1
  / \     / \
 /   \   /   \
2     3 2     3
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
   1       1
  /         \
 /           \
2             2
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
   1       1
  / \     / \
 /   \   /   \
2     1 1     2
Input: p = [1,2,1], q = [1,1,2]
Output: false


Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
*/

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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// 1. Iterative Approach
		// Time complexity:     O(N)
		// Space complexity:    O(lgN), worst cast O(N)
		if (!p && !q) return true;
		if (!p || !q) return false;
		std::queue<TreeNode*> q1;
		std::queue<TreeNode*> q2;
		q1.push(p);
		q2.push(q);
		while (!q1.empty() && !q2.empty()) {
			auto t1 = q1.front();
			auto t2 = q2.front();
			q1.pop();
			q2.pop();
			if (t1->val != t2->val) {
				return false;
			}
			if (t1->left) {
				if (!t2->left) {
					return false;
				}
				q1.push(t1->left);
				q2.push(t2->left);
			}
			else {
				if (t2->left) {
					return false;
				}
			}
			if (t1->right) {
				if (!t2->right) {
					return false;
				}
				q1.push(t1->right);
				q2.push(t2->right);
			}
			else {
				if (t2->right) {
					return false;
				}
			}

		}
		return true;

		// 2. Recursive Approach
		// Time complexity:     O(N)
		// Space complexity:    O(lgN), worst cast O(N)
		/*if (!p && !q) return true;
		if (!p || !q) return false;

		return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);*/
	}
};

/*
Tips:
*/