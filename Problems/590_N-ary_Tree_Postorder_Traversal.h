#pragma once

/* 
590. N-ary Tree Postorder Traversal
https://leetcode.com/problems/n-ary-tree-postorder-traversal/

Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

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
Output: [1,3,5,6,2,4]

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
    void postOrder(Node* root, std::vector<int>& v) {
        if (!root) return;
        for (auto& c : root->children) {
            postOrder(c, v);
        }
        v.push_back(root->val);
    }

    std::vector<int> postorder(Node* root) {
        // 1. Recursive approach
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> res;
        postOrder(root, res);
        return res;*/

        // 2. Iterative approach with reversal
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        /*std::vector<int> res;
        if (!root) return res;

        std::stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            for (size_t i = 0; i < root->children.size(); ++i) {
                s.push(root->children[i]);
            }
            res.push_back(root->val);
        }
        std::reverse(res.begin(), res.end());
        return res;*/

        // 3. Iterative approach without reversal
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::vector<int> res;
        if (!root) return res;

        std::stack<std::pair<Node*, int>> s;
        s.emplace(root, 0);
        while (!s.empty()) {
            // auto& [node, index] = s.top();   // C++17
            Node* node = s.top().first;
            int& index = s.top().second;
            if (index == node->children.size()) {
                res.push_back(node->val);
                s.pop();
            }
            else {
                s.emplace(node->children[index++], 0);
            }
        }
        return res;
};

/*
Tips:
    1. Postorder traversal goes in order L-R-V, which is equivalent to a traversal in order V-R-L with a reversal
*/