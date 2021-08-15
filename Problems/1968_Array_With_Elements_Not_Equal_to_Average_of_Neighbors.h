#pragma once

/* 
1968. Array With Elements Not Equal to Average of Neighbors
https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

You are given a 0-indexed array nums of distinct integers. You want to rearrange the elements in the array such that every element in the rearranged array is not equal to the average of its neighbors.

More formally, the rearranged array should have the property such that for every i in the range 1 <= i < nums.length - 1, (nums[i-1] + nums[i+1]) / 2 is not equal to nums[i].

Return any rearrangement of nums that meets the requirements.



Example 1:

Input: nums = [1,2,3,4,5]
Output: [1,2,4,5,3]
Explanation:
When i=1, nums[i] = 2, and the average of its neighbors is (1+4) / 2 = 2.5.
When i=2, nums[i] = 4, and the average of its neighbors is (2+5) / 2 = 3.5.
When i=3, nums[i] = 5, and the average of its neighbors is (4+3) / 2 = 3.5.
Example 2:

Input: nums = [6,2,0,9,7]
Output: [9,7,6,2,0]
Explanation:
When i=1, nums[i] = 7, and the average of its neighbors is (9+6) / 2 = 7.5.
When i=2, nums[i] = 6, and the average of its neighbors is (7+2) / 2 = 4.5.
When i=3, nums[i] = 2, and the average of its neighbors is (6+0) / 2 = 3.


Constraints:

3 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) {
        // 1. In-place sorting and swapping with backing
        // Time complexity:     O(NlgN)
        // Space complexity:    O(1)
        /*std::sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size() - 1; ++i) {
            if (2 * nums[i] == nums[i - 1] + nums[i + 1]) {
                std::swap(nums[i], nums[i + 1]);
                if (i != 1) {
                    i -= 2;
                }
            }
        }
        return nums;*/

        // 2. In-place sorting and swapping by 2 steps
        // Time complexity:     O(NlgN)
        // Space complexity:    O(1)
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2) {
            std::swap(nums[i - 1], nums[i]);
        }
        return nums;

        // 3. 2-pass swapping
        // Time complexity:     O(N)
        // Space complexity:    O(1)
        /*for (size_t i = 1; i < nums.size() - 1; ++i) {
            if (2 * nums[i] == nums[i - 1] + nums[i + 1]) {
                std::swap(nums[i], nums[i + 1]);
            }
        }
        for (size_t i = nums.size() - 2; i > 0; --i) {
            if (2 * nums[i] == nums[i - 1] + nums[i + 1]) {
                std::swap(nums[i], nums[i + 1]);
            }
        }
        return nums;*/

        // 4. Sort and pick
        // Time complexity:     O(NlgN)
        // Space complexity:    O(N)
        /*std::sort(nums.begin(), nums.end());
        std::vector<int> res(nums.size());
        int i = 0;
        int j = 0;
        while (j < res.size()) {
            res[j] = nums[i];
            ++i;
            j += 2;
        }
        j = 1;
        while (j < res.size()) {
            res[j] = nums[i];
            ++i;
            j += 2;
        }
        return res;*/
    }
};

/*
Tips:
*/