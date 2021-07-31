#pragma once

/* 
677. Map Sum Pairs
https://leetcode.com/problems/map-sum-pairs/

Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.


Example 1:

Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)


Constraints:

1 <= key.length, prefix.length <= 50
key and prefix consist of only lowercase English letters.
1 <= val <= 1000
At most 50 calls will be made to insert and sum.
*/

#include <string>
#include <unordered_map>

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    // 1. Hashmap for keys and vals
    // Time complexity:     O(1) for insertion, O(NP) for summation
    // Space complexity:    O(N)
    void insert(std::string key, int val) {
        m[key] = val;
    }

    int sum(std::string prefix) {
        int sum = 0;
        for (auto& e : m) {
            if (e.first.find(prefix) == 0) {
                sum += e.second;
            }
        }
        return sum;
    }

    std::unordered_map<std::string, int> m;

    // 2. Hashmap for prefixes and vals
    // Time complexity:     O(P^2) for insertion, O(1) for summation
    // Space complexity:    O(N * P)
    /*void insert(std::string key, int val) {
        for (size_t i = 0; i < key.size(); ++i) {
            m[key.substr(0, i + 1)] += val;
        }
    }

    int sum(std::string prefix) {
        return m[prefix];
    }

    std::unordered_map<std::string, int> m;*/
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

/*
Tips:
*/