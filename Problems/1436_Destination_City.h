#pragma once

/* 
1436. Destination City
https://leetcode.com/problems/destination-city/

You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.



Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo"
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are:
"D" -> "B" -> "C" -> "A".
"B" -> "C" -> "A".
"C" -> "A".
"A".
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"


Constraints:

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        // 1. Use std::unordered_map
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::unordered_map<std::string, bool> mp;
        for (auto& p : paths) {
            mp[p[0]] = true;
            if (mp.find(p[1]) == mp.end()) {
                mp[p[1]] == false;
            }
        }
        for (auto& e : mp) {
            if (e.second == false) {
                return e.first;
            }
        }

        // 2. Use std::unordered_set
        // Time complexity:     O(N)
        // Space complexity:    O(N)
        std::unordered_set<std::string> st;
        for (auto& p : paths) {
            st.insert(p[0]);
        }
        for (auto& p : paths) {
            if (!st.count(p[1])) {
                return p[1];
            }
        }

        return "";
    }
};

/*
Tips:
    1.(auto& p : paths) is somehow faster than index retrieval while traversing
    2.std::unordered_set (and std::set) is handy where the problem is either "true" or "false"
*/