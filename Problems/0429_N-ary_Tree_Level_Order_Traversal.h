#pragma once

/* 
429. N-ary Tree Level Order Traversal
https://leetcode.com/problems/two-sum/

Given an n-ary tree, return the level order traversal of its nodes' values.

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
Output: [[1],[3,2,4],[5,6]]

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
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]


Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]
*/

#include <vector>
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
    void levelorder(Node* root, std::vector<std::vector<int>>& v, int l) {
        if (!root) return;
        while (v.size() < l) {
            v.push_back(std::vector<int>());
        }
        v[l - 1].push_back(root->val);
        for (size_t i = 0; i < root->children.size(); ++i) {
            levelorder(root->children[i], v, l + 1);
        }
    }

    std::vector<std::vector<int>> levelOrder(Node* root) {
        // 1. Iteration (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        /*std::vector<std::vector<int>> v;
        if (!root) return v;
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            std::vector<int> vt(s);
            for (size_t i = 0; i < s; ++i) {
                auto t = q.front();
                q.pop();
                vt[i] = t->val;
                for (size_t j = 0; j < t->children.size(); ++j) {
                    q.push(t->children[j]);
                }
            }
            v.push_back(vt);
        }
        return v;*/

        // 2. Iteration with memoization (BFS)
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        /*std::vector<std::vector<int>> v;
        if (!root) return v;

        std::queue<std::pair<int, Node*>> q;
        q.push(std::make_pair(1, root));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            while (v.size() < t.first) {
                v.push_back(std::vector<int>());
            }
            v[t.first - 1].push_back(t.second->val);
            for (size_t i = 0; i < t.second->children.size(); ++i) {
                q.push(std::make_pair(t.first + 1, t.second->children[i]));
            }
        }
        return v;*/

        // 3. Recursion (DFS)
        // Time complexity:     O(N)
        // Space complexity:    O(lgN), worst case O(N)
        std::vector<std::vector<int>> v;
        levelorder(root, v, 1);
        return v;
    }
};

/*
Tips:
*/