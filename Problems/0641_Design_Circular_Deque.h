#pragma once

/* 
641. Design Circular Deque
https://leetcode.com/problems/design-circular-deque/

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.


Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4


Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
*/

#include <deque>

class MyCircularDeque {
public:
    struct Node {
        int val;
        Node* prev;
        Node* post;

        Node(int v, Node* pv = nullptr, Node* pt = nullptr) :
            val(v), prev(pv), post(pt)
        {}
    };

    // 1. Doubly-linked list
    // Time complexity:     O(1)
    // Space complexity:    O(N)
    // Initialize your data structure here. Set the size of the deque to be k.
    MyCircularDeque(int k) {
        mMaxSize = k;
        mSize = 0;
        mFront = nullptr;
        mLast = nullptr;
    }

    // Adds an item at the front of Deque. Return true if the operation is successful.
    bool insertFront(int value) {
        if (mSize < mMaxSize) {
            if (mFront) {
                Node* f = new Node(value);
                f->post = mFront;
                mFront->prev = f;
                mFront = f;
            }
            else {
                mFront = new Node(value);
                mLast = mFront;
            }
            ++mSize;
            return true;
        }
        return false;
    }

    // Adds an item at the rear of Deque. Return true if the operation is successful.
    bool insertLast(int value) {
        if (mSize < mMaxSize) {
            if (mLast) {
                Node* l = new Node(value);
                l->prev = mLast;
                mLast->post = l;
                mLast = l;
            }
            else {
                mLast = new Node(value);
                mFront = mLast;
            }
            ++mSize;
            return true;
        }
        return false;
    }

    // Deletes an item from the front of Deque. Return true if the operation is successful.
    bool deleteFront() {
        if (mFront) {
            auto tmp = mFront;
            mFront = mFront->post;
            if (mFront) {
                mFront->prev = nullptr;
            }
            else {
                mLast = nullptr;
            }
            tmp->post = nullptr;
            --mSize;
            return true;
        }
        return false;
    }

    // Deletes an item from the rear of Deque. Return true if the operation is successful.
    bool deleteLast() {
        if (mLast) {
            auto tmp = mLast;
            mLast = mLast->prev;
            if (mLast) {
                mLast->post = nullptr;
            }
            else {
                mFront = nullptr;
            }
            tmp->prev = nullptr;
            --mSize;
            return true;
        }
        return false;
    }

    // Get the front item from the deque.
    int getFront() {
        if (mFront) {
            return mFront->val;
        }
        return -1;
    }

    // Get the last item from the deque.
    int getRear() {
        if (mLast) {
            return mLast->val;
        }
        return -1;
    }

    // Checks whether the circular deque is empty or not.
    bool isEmpty() {
        return mSize == 0;
    }

    // Checks whether the circular deque is full or not.
    bool isFull() {
        return mSize == mMaxSize;
    }

    int mMaxSize;
    int mSize;
    Node* mFront;
    Node* mLast;

    // 2. std::deque
    // Time complexity:     O(1)
    // Space complexity:    O(N)
    /*// Initialize your data structure here. Set the size of the deque to be k.
    MyCircularDeque(int k) {
        mMaxSize = k;
    }

    // Adds an item at the front of Deque. Return true if the operation is successful.
    bool insertFront(int value) {
        if (mData.size() < mMaxSize) {
            mData.push_front(value);
            return true;
        }
        return false;
    }

    // Adds an item at the rear of Deque. Return true if the operation is successful.
    bool insertLast(int value) {
        if (mData.size() < mMaxSize) {
            mData.push_back(value);
            return true;
        }
        return false;
    }

    // Deletes an item from the front of Deque. Return true if the operation is successful.
    bool deleteFront() {
        if (mData.size() > 0) {
            mData.pop_front();
            return true;
        }
        return false;
    }

    // Deletes an item from the rear of Deque. Return true if the operation is successful.
    bool deleteLast() {
        if (mData.size() > 0) {
            mData.pop_back();
            return true;
        }
        return false;
    }

    // Get the front item from the deque.
    int getFront() {
        if (mData.size() > 0) {
            return mData.front();
        }
        return -1;
    }

    // Get the last item from the deque.
    int getRear() {
        if (mData.size() > 0) {
            return mData.back();
        }
        return -1;
    }

    // Checks whether the circular deque is empty or not.
    bool isEmpty() {
        return mData.empty();
    }

    // Checks whether the circular deque is full or not.
    bool isFull() {
        return mData.size() == mMaxSize;
    }

    int mMaxSize;
    std::deque<int> mData;*/
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

/*
Tips:
*/