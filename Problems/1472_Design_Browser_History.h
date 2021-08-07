#pragma once

/* 
1472. Design Browser History
https://leetcode.com/problems/design-browser-history/

You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.


Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"


Constraints:

1 <= homepage.length <= 20
1 <= url.length <= 20
1 <= steps <= 100
homepage and url consist of  '.' or lower case English letters.
At most 5000 calls will be made to visit, back, and forward.
*/

#include <stack>
#include <vector>
#include <algorithm>

class BrowserHistory {
public:
    // 1. Two stack
    // Time complexity:
    //      visit:          O(N^2)
    //       back:          O(S)
    //    forward:          O(S)
    // Space complexity:
    //      visit:          O(N)
    //       back:          O(1)
    //    forward:          O(1)
    /*BrowserHistory(std::string homepage) {
        bs.push(homepage);
    }

    void visit(std::string url) {
        bs.push(url);
        while (!fs.empty()) {
            fs.pop();
        }
    }

    std::string back(int steps) {
        int i = 0;
        while (i < steps && bs.size() > 1) {
            std::string cur = bs.top();
            bs.pop();
            fs.push(cur);
            ++i;
        }
        return bs.top();
    }

    std::string forward(int steps) {
        int i = 0;
        while (i < steps && !fs.empty()) {
            std::string cur = fs.top();
            fs.pop();
            bs.push(cur);
            ++i;
        }
        return bs.top();
    }

    std::stack<std::string> bs;
    std::stack<std::string> fs;*/

    // 2. Doubly-linked list
    // Time complexity:
    //      visit:          O(N)
    //       back:          O(S)
    //    forward:          O(S)
    // Space complexity:
    //      visit:          O(N)
    //       back:          O(1)
    //    forward:          O(1)
    /*struct Node {
        std::string val;
        Node* prev;
        Node* post;

        Node(const std::string& s, Node* pv = nullptr, Node* pt = nullptr) :
            val(s),
            prev(pv),
            post(pt)
        {}
    };

    BrowserHistory(std::string homepage) {
        mNode = new Node(homepage);
    }

    void visit(std::string url) {
        Node* newNode = new Node(url);
        newNode->prev = mNode;
        mNode->post = newNode;
        mNode = newNode;
    }

    std::string back(int steps) {
        int i = 0;
        while (i < steps && mNode->prev) {
            mNode = mNode->prev;
            ++i;
        }
        return mNode->val;
    }

    std::string forward(int steps) {
        int i = 0;
        while (i < steps && mNode->post) {
            mNode = mNode->post;
            ++i;
        }
        return mNode->val;
    }

    Node* mNode;*/

    // 3. Vector resizing
    //      visit:          O(N)
    //       back:          O(S)
    //    forward:          O(S)
    // Space complexity:
    //      visit:          O(N)
    //       back:          O(1)
    //    forward:          O(1)
    BrowserHistory(std::string homepage) {
        mPos = 0;
        mV.push_back(homepage);
    }

    void visit(std::string url) {
        mV.resize(++mPos);
        mV.push_back(url);
    }

    std::string back(int steps) {
        mPos = std::max(0, mPos - steps);
        return mV[mPos];
    }

    std::string forward(int steps) {
        mPos = std::min((int)mV.size() - 1, mPos + steps);
        return mV[mPos];
    }

    std::vector<std::string> mV;
    int mPos;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

/*
Tips:
*/