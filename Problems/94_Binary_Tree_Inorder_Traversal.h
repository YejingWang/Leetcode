#pragma once

/* 
94. Binary Tree Inorder Traversal
https://leetcode.com/problems/binary-tree-inorder-traversal/

Given the root of a binary tree, return the inorder traversal of its nodes' values.



Example 1:
1
 \
  \
   2
  /
 /
3
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
   1
  /
 /
2
Input: root = [1,2]
Output: [2,1]

Example 5:
1
 \
  \
   2
Input: root = [1,null,2]
Output: [1,2]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?
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
	void inorder(TreeNode* root, std::vector<int>& v) {
		if (!root) return;
		inorder(root->left, v);
		v.push_back(root->val);
		inorder(root->right, v);
	}

	void goAlongLeft(TreeNode* root, std::stack<TreeNode*>& s) {
		while (root) {
			s.push(root);
			root = root->left;
		}
	}

	std::vector<int> inorderTraversal(TreeNode* root) {
		// 1. Recursive approach
		// Time complexity:     O(N)
		// Space complexity:    O(N)
		/*std::vector<int> res;
		inorder(root, res);
		return res;*/

		// 2. Iterative approach
		// Time complexity:     O(N)
		// Space complexity:    O(N)
		std::vector<int> res;
		std::stack<TreeNode*> s;
		while (true) {
			goAlongLeft(root, s);
			if (s.empty()) break;
			root = s.top();
			s.pop();
			res.push_back(root->val);
			root = root->right;
		}
		return res;
	}
};

/*
Tips:
*/