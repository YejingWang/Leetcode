#pragma once

/* 
559. Maximum Depth of N-ary Tree
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).



Example 1:

      1
     /|\
    / | \
   3  2  4
  / \
 /   \
5     6

Input: root = [1,null,3,2,4,null,5,6]
Output: 3

Example 2:
        1
     /|    |\
    / |    | \
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
Output: 5


Constraints:

The total number of nodes is in the range [0, 10^4].
The depth of the n-ary tree is less than or equal to 1000.
*/

#include <vector>
#include <stack>
#include <queue>

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
    int maxDepth(Node* root) {
        // 1. Recursion (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*if (!root) return 0;
        int max = 0;
        for (size_t i = 0; i < root->children.size(); ++i) {
            int depth = maxDepth(root->children[i]);
            max = depth > max ? depth : max;
        }
        return 1 + max;*/

        // 2. Iteration with stack (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(H)
        /*if (!root) return 0;
        std::stack<std::pair<Node*, int>> s;
        s.push(std::make_pair(root, 1));
        int max = 0;
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            max = t.second > max ? t.second : max;
            for (size_t i = 0; i < t.first->children.size(); ++i) {
                s.push(std::make_pair(t.first->children[i], t.second + 1));
            }
        }
        return max;*/

        // 3. Iteration with queue (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        if (!root) return 0;
        std::queue<Node*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                auto t = q.front();
                q.pop();;
                for (size_t j = 0; j < t->children.size(); ++j) {
                    q.push(t->children[j]);
                }
            }
            ++depth;
        }
        return depth;
    }
};

/*
Tips:
*/