#pragma once

/* 
1022. Sum of Root To Leaf Binary Numbers
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

You are given the root of a binary tree where each node has a value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers. The answer is guaranteed to fit in a 32-bits integer.



Example 1:

        1
       / \
      /   \
	 /     \
    0       1
   / \     / \
  /   \   /   \
 0     1 0     1 

Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Example 2:

Input: root = [0]
Output: 0

Example 3:

Input: root = [1]
Output: 1

Example 4:

Input: root = [1,1]
Output: 3


Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.
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
	int preOrderDFS(TreeNode* root, int val) {
		if (!root) return 0;
		val = root->val + 2 * val;
		return root->left == root->right ? val : preOrderDFS(root->left, val) + preOrderDFS(root->right, val);
	}

	int sumRootToLeaf(TreeNode* root) {
		// 1. Recursive approach
		// Time complexity:     O(N)
		// Space complexity:    O(H)
		/*int val = 0;
		return preOrderDFS(root, val);*/

		// 2. Iterative approach
		// Time complexity:     O(N)
		// Space complexity:    O(H)
		/*if (!root) return 0;
		int sum = 0;
		std::stack<std::pair<TreeNode*, int>> s;
		s.push({ root, 0 });
		while (!s.empty()) {
			root = s.top().first;
			int curSum = s.top().second;
			s.pop();
			curSum = 2 * curSum + root->val;
			if (root->left == root->right) {
				sum += curSum;
			}
			if (root->left) {
				s.push({ root->left, curSum });
			}
			if (root->right) {
				s.push({ root->right, curSum });
			}
		}
		return sum;*/

		// 3. Morris preorder traversal
		// Time complexity:     O(N)
		// Space complexity:    O(1)
		int sum = 0;
		int curSum = 0;
		int steps = 0;
		TreeNode* pred = nullptr;

		while (root) {
			if (root->left) {
				pred = root->left;
				steps = 1;
				while (pred->right && pred->right != root) {
					pred = pred->right;
					++steps;
				}

				if (!pred->right) {
					curSum = curSum * 2 + root->val;
					pred->right = root;
					root = root->left;
				}
				else {
					if (!pred->left) {
						sum += curSum;
					}
					for (int i = 0; i < steps; ++i) {
						curSum /= 2;
					}
					pred->right = nullptr;
					root = root->right;
				}
			}
			else {
				curSum = curSum * 2 + root->val;
				if (!root->right) {
					sum += curSum;
				}
				root = root->right;
			}
		}
		return sum;
	}
};

/*
Tips:
	1.root->left == root->right can be used to determine if this node has any child (i.e. is a leaf node)
	2. Morris traversal only takes O(1) space
*/