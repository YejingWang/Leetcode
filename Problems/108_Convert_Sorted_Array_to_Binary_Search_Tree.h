#pragma once

/* 
108. Convert Sorted Array to Binary Search Tree
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.



Example 1:
    0
   / \
  /   \
-10    5
   \    \
    \    \
    -3    9
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
    3   1
   /     \
  /       \
 1         3
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.


Constraints:

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in a strictly increasing order.
*/

#include <vector>

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
    TreeNode* convert(const std::vector<int>& nums, const int begin, const int end) {
        if (begin >= end) return nullptr;
        TreeNode* root = new TreeNode();
        int mid = begin + (end - begin) / 2;
        root->val = nums[mid];
        root->left = convert(nums, begin, mid);
        root->right = convert(nums, mid + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        // 1. Recursion
        // Time complexity:     O(N)
        // Space complexity:    O(lgN)
        return convert(nums, 0, nums.size());
    }
};

/*
Tips:
*/