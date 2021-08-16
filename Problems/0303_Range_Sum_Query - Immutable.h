#pragma once

/* 
303. Range Sum Query - Immutable
https://leetcode.com/problems/range-sum-query-immutable/

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3


Constraints:

1 <= nums.length <= 10^4
-10^5 <= nums[i] <= 10^5
0 <= left <= right < nums.length
At most 10^4 calls will be made to sumRange.
*/

#include <vector>

class NumArray {
public:
    // 1. Brute force
    // Time complexity:
    //      construction:   O(N)
    //      sumRange:       O(L)
    // Space complexity:    O(1)
    /*NumArray(std::vector<int>& nums) :
        mNum(nums)
    {}

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; ++i) {
            sum += mNum[i];
        }
        return sum;
    }

    std::vector<int> mNum;*/

    // 2. Store all possible sums
    // Time complexity:
    //      construction:   O(N^2)
    //      sumRange:       O(1)
    // Space complexity:    O(N^2)
    /*NumArray(std::vector<int>& nums) {
        mSize = nums.size();
        mSums.resize(mSize * mSize, 0);
        for (size_t i = 0; i < mSize; ++i) {
            int sum = 0;
            for (size_t j = i; j < mSize; ++j) {
                sum += nums[j];
                mSums[i * mSize + j] = sum;
            }
        }
    }

    int sumRange(int left, int right) {
        return mSums[left * mSize + right];
    }

    std::vector<int> mSums;
    int mSize;*/

    // 3. Store once for each left
    // Time complexity:
    //      construction:   O(N)
    //      sumRange:       O(L)
    // Space complexity:    O(N)
    /*NumArray(std::vector<int>& nums) :
        mNum(nums),
        mSums(nums.size(), std::make_pair(-1, -1))
    {}

    int sumRange(int left, int right) {
        if (mSums[left].first < 0) {
            int sum = 0;
            for (size_t i = left; i <= right; ++i) {
                sum += mNum[i];
            }
            mSums[left].first = right;
            mSums[left].second = sum;
            return sum;
        }
        else {
            auto& [prevRight, sum] = mSums[left];
            if (right > prevRight) {
                while (right > prevRight) {
                    ++prevRight;
                    sum += mNum[prevRight];
                }
            }
            else {
                while (right < prevRight) {
                    sum -= mNum[prevRight];
                    --prevRight;
                }
            }
            return sum;
        }
        return -1;
    }

    std::vector<int> mNum;
    std::vector<std::pair<int, int>> mSums;*/

    // 4. Prefix sum
    // Time complexity:
    //      construction:   O(N)
    //      sumRange:       O(1)
    // Space complexity:    O(1)
    NumArray(std::vector<int>& nums) :
        mSums(nums)
    {
        for (size_t i = 1; i < nums.size(); ++i) {
            mSums[i] += mSums[i - 1];
        }
    }

    int sumRange(int left, int right) {
        return left == 0 ? mSums[right] : mSums[right] - mSums[left - 1];
    }

    std::vector<int> mSums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

/*
Tips:
*/