#pragma once

/* 
589. N-ary Tree Preorder Traversal
https://leetcode.com/problems/n-ary-tree-preorder-traversal/

Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)



Example 1:

      1
     /|\
    / | \
   3  2  4
  / \
 /   \
5     6

Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Example 2:

        1
   /  |    |  \
  /   |    |   \
 /    |    |    \
2     3    4     5
     /\    |    / \
    /  \   |   /   \
   6    7  8  9     10
        |  |  |
        |  |  |
       11 12  13
        |
        |
       14

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]


Constraints:

The number of nodes in the tree is in the range [0, 10^4].
0 <= Node.val <= 10^4
The height of the n-ary tree is less than or equal to 1000.


Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <vector>
#include <stack>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void preOrder(Node* root, std::vector<int>& v) {
        if (!root) return;
        v.push_back(root->val);
        for (auto c : root->children) {
            preOrder(c, v);
        }
    }

    std::vector<int> preorder(Node* root) {
        // 1. Recursive approach with vector insertion
        // Time complexity:     O(N^2)
        // Space complexity:    O(N)
        /*std::vector<int> res;
        if (!root) return res;

        res.push_back(root->val);
        for (auto c : root->children) {
            std::vector<int> vec = preorder(v);
            res.insert(res.end(), vec.begin(), vec.end());
        }

        return res;*/

        // 2. Better recursive approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> res;
        preOrder(root, res);
        return res;*/

        // 3. Iterative approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::vector<int> res;
        if (!root) return res;

        std::stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            res.push_back(root->val);
            for (int i = root->children.size(); i > 0; --i) {
                s.push(root->children[i - 1]);
            }
        }
        return res;
    }
};

/*
Tips:
*/