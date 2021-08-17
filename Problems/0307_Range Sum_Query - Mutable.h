#pragma once

/* 
307. Range Sum Query - Mutable
https://leetcode.com/problems/range-sum-query-mutable/

Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8


Constraints:

1 <= nums.length <= 3 * 10^4
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 10^4 calls will be made to update and sumRange.
*/

#include <vector>

class NumArray {
public:
    // 1. Naive prefix sum
    // Time complexity:
    //      construction:   O(N)
    //            update:   O(N)
    //          sumRange:   O(1)
    // Space complexity:    O(N)
    /*NumArray(std::vector<int>& nums) :
        mNum(nums),
        mSums(nums)
    {
        for (size_t i = 1; i < mSums.size(); ++i) {
            mSums[i] += mSums[i - 1];
        }
    }

    void update(int index, int val) {
        int diff = val - mNum[index];
        mNum[index] = val;
        for (size_t i = index; i < mSums.size(); ++i) {
            mSums[i] += diff;
        }
    }

    int sumRange(int left, int right) {
        return left == 0 ? mSums[right] : mSums[right] - mSums[left - 1];
    }

    std::vector<int> mSums;
    std::vector<int> mNum;*/

    // 2. Square decomposition
    // Time complexity:
    //      construction:   O(N)
    //            update:   O(1)
    //          sumRange:   O(lgN)
    // Space complexity:    O(lgN)
    NumArray(std::vector<int>& nums) :
        mNums(nums)
    {
        double l = std::sqrt(mNums.size());
        mL = (int)ceil(mNums.size() / l);
        sqrtSums.resize(mL);
        for (size_t i = 0; i < mNums.size(); ++i) {
            sqrtSums[i / mL] += nums[i];
        }
    }

    void update(int index, int val) {
        int sqrtIndex = index / mL;
        sqrtSums[sqrtIndex] = sqrtSums[sqrtIndex] - mNums[index] + val;
        mNums[index] = val;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        int ls = left / mL;
        int rs = right / mL;
        if (ls == rs) {
            for (int i = left; i <= right; ++i) {
                sum += mNums[i];
            }
        }
        else {
            for (int i = left; i <= (ls + 1) * mL - 1; ++i) {
                sum += mNums[i];
            }
            for (int i = ls + 1; i <= rs - 1; ++i) {
                sum += sqrtSums[i];
            }
            for (int i = rs * mL; i <= right; ++i) {
                sum += mNums[i];
            }
        }
        return sum;
    }

    std::vector<int> mNums;
    int mL;
    std::vector<int> sqrtSums;

    // 3. Segment tree
    // Time complexity:
    //      construction:   O(N)
    //            update:   O(lgN)
    //          sumRange:   O(lgN)
    // Space complexity:    O(N)
    /*NumArray(std::vector<int>& nums) :
        mSize(nums.size()),
        mTree(2 * mSize)
    {
        for (size_t i = 0; i < mSize; ++i) {
            mTree[mSize + i] = nums[i];
        }
        for (size_t i = mSize - 1; i > 0; --i) {
            mTree[i] = mTree[2 * i] + mTree[2 * i + 1];
        }
    }

    void update(int index, int val) {
        int i = index + mSize;
        mTree[i] = val;
        while (i > 0) {
            int left = i;
            int right = i;
            if (i % 2 == 0) {
                right = i + 1;
            }
            else {
                left = i - 1;
            }
            mTree[i / 2] = mTree[left] + mTree[right];
            i /= 2;
        }
    }

    int sumRange(int left, int right) {
        int l = left + mSize;
        int r = right + mSize;
        int sum = 0;
        while (l <= r) {
            if (l % 2 == 1) {
                sum += mTree[l];
                ++l;
            }
            if (r % 2 == 0) {
                sum += mTree[r];
                --r;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }

    int mSize;
    std::vector<int> mTree;*/
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/*
Tips:
*/