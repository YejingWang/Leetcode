#pragma once

/* 
836. Rectangle Overlap
https://leetcode.com/problems/two-sum/

An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.



Example 1:
Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true

Example 2:
Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false

Example 3:
Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
Output: false


Constraints:

rect1.length == 4
rect2.length == 4
-10^9 <= rec1[i], rec2[i] <= 10^9
rec1 and rec2 represent a valid rectangle with a non-zero area.
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        // 1. By position
        // Time complexity:     O(1)
        // Space complexity:    O(1)
        //return !(rec2[0] >= rec1[2] || rec2[1] >= rec1[3] || rec2[2] <= rec1[0] || rec2[3] <= rec1[1]);
        return rec2[0] < rec1[2] && rec2[1] < rec1[3] && rec2[2] > rec1[0] && rec2[3] > rec1[1];

        // 2. By area
        // Time complexity:     O(1)
        // Space complexity:    O(1)
        /*return std::min(rec1[2], rec2[2]) > std::max(rec1[0], rec2[0])
            && std::min(rec1[3], rec2[3]) > std::max(rec1[1], rec2[1]);*/
    }
};

/*
Tips:
    1. For 1d cases, two line segments (x1, x2) and (x3, x4) intersects only if x1 < x4 && x3 < x2
*/