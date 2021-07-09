#pragma once

/* 
101. Symmetric Tree
https://leetcode.com/problems/symmetric-tree/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
        1
      / | \
     /  |  \
    /   |   \
   2    |    2
  / \   |   / \
 /   \  |  /   \
3     4 | 4     3

Example 2:
      1
	 / \
    /   \
   2     2
    \     \
     \     \
      3     3
Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
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
	bool isTwoTreeSymmetric(TreeNode* r1, TreeNode* r2) {
		if (!r1 && !r2) return true;
		if (!r1 || !r2) return false;
		if (r1->val != r2->val) return false;
		return isTwoTreeSymmetric(r1->left, r2->right) && isTwoTreeSymmetric(r1->right, r2->left);
	}

	bool isSymmetric(TreeNode* root) {
		// 1. Recursive Approach
		// Time complexity:     O(N)
		// Space complexity:    O(lgN), worst cast O(N)
		if (!root) return true;
		return isTwoTreeSymmetric(root->left, root->right);

		// 2. Iterative Approach
		// Time complexity:     O(N)
		// Space complexity:    O(lgN), worst cast O(N)
		/*if (!root) return true;
		std::queue<TreeNode*> q1;
		std::queue<TreeNode*> q2;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty()) {
			auto t1 = q1.front();
			auto t2 = q2.front();
			q1.pop();
			q2.pop();
			if (!t1) {
				if (t2) {
					return false;
				}
			}
			else {
				if (!t2) {
					return false;
				}
				if (t1->val != t2->val) {
					return false;
				}
				q1.push(t1->left);
				q1.push(t1->right);
				q2.push(t2->right);
				q2.push(t2->left);
			}

		}
		return true;*/
	}
};

/*
Tips:
*/